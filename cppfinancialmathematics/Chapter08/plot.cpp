#include "plot.h"
using namespace std;

/**
 * Ex. 8.6.2
 */
class LineChart {
public:
    string chartTitle;
    void plot(const vector<double>& x, const vector<double>& y);
    void dataChart(ostream& out, const vector<double>& x, const vector<double>& y);
    void setTitle(string& name);
private:
    void writetopChartHtml(ostream& out);
    void writeBottomChartHtml(ostream& out);
};

void LineChart::setTitle(string& name) {
    chartTitle = name;
}

void LineChart::writetopChartHtml(ostream& out) {
  out << "<html>\n";
  out << "  <head>\n";
  out << "    <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n";
  out << "    <script type=\"text/javascript\">\n";
  out << "      google.charts.load(\'current', {\'packages\':[\'corechart\']});\n";
  out << "      google.charts.setOnLoadCallback(drawChart);\n";
  out << "      function drawChart() {\n";
  out << "        var data = google.visualization.arrayToDataTable([\n";
}

void LineChart::writeBottomChartHtml(ostream& out) {
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

void LineChart::dataChart(ostream& out, const vector<double>& x, const vector<double>& y) {
    out << "          ['x', 'y'],\n";
    for (int i=0; i < x.size(); i++) {
        out << "          [";
        out << x[i] << "," << y[i];
        out << "      ],\n";
    }
}

void LineChart::plot(const vector<double>& x, const vector<double>& y) {
    ofstream out;
    out.open("test862.html");
    writetopChartHtml(out);
    dataChart(out, x, y);
    writeBottomChartHtml(out);
}


/**
 * Testing
 */

void testLineChart() {
    LineChart lc;
    vector<double> x(5, 0.0);
    vector<double> y(5, 1.0);
    for (int i=0; i < 5; i++) {
        x[i] = i;
        y[i] = i*i;
    }
    string title = "This Dumb Chart";
    lc.setTitle(title);
    lc.plot(x, y);
}
