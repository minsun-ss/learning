#include "plot.h"
using namespace std;


static void writetopChartHtml(ostream& out) {
  out << "<html>\n";
  out << "  <head>\n";
  out << "    <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n";
  out << "    <script type=\"text/javascript\">\n";
  out << "      google.charts.load(\'current', {\'packages\':[\'corechart\']});\n";
  out << "      google.charts.setOnLoadCallback(drawChart);\n";
  out << "      function drawChart() {\n";
  out << "        var data = google.visualization.arrayToDataTable([\n";
}

static void writebottomChartHtml(ostream& out, string& chartTitle) {
    out << "      ]);\n";
    out << "\n";
    out << "    var options = {\n";
    out << "      title: '" << chartTitle << "',\n";
    out << "      legend: { position: 'bottom' }\n";
    out << "    };\n";
    out << "    var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));\n";
    out << "    chart.draw(data, options);\n";
    out << "    }\n";
    out << "    </script>\n";
    out << "</head>\n";
    out << "<body>\n";
    out << "  <div id=\"curve_chart\" style=\"width: 900px; height: 500px\"></div>\n";
    out << "</body>\n";
    out << "</html>\n";
}

void dataChart(ostream& out, const vector<double>& x, const vector<double>& y) {
    out << "          ['x', 'y'],\n";
    for (int i=0; i < x.size(); i++) {
        out << "          [";
        out << x[i] << "," << y[i];
        out << "      ],\n";
    }
}

void plot(string name, const vector<double>& x, const vector<double>& y) {
    ofstream out;
    out.open("test778.html");
    writetopChartHtml(out);
    dataChart(out, x, y);
    writebottomChartHtml(out, name);
}

/**
 * Testing
 */

void testPlot() {
    vector<double> x(5, 0.0);
    vector<double> y(5, 1.0);
    for (int i=0; i < 5; i++) {
        x[i] = i;
        y[i] = i*i;
    }
    string n = "MyChart";
    plot(n, x, y);
}
