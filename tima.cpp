#include "tima.h"

int main(int argc, char ** argv) {
    Tima tima = Tima(argc, argv);
    //QResource::registerResource("resources.qrc");
    return 0;
}

Tima::Tima(int argc, char** argv) {
    fs::path timadir = fs::path(getenv("HOME")) / ".tima";
    if (!fs::exists(timadir)) {
        cout << timadir << " does not exist!" << endl;
        fs::create_directory(timadir);
    }

    // todos
    fs::path todofile = fs::path(timadir) / "todo.xml";
    if (!fs::exists(todofile)){
        cout << todofile << " does not exist!" << endl;
        ofstream ofs(todofile.c_str());
    } else {
        cout << todofile << " exists!" << endl;
    }

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    app.exec();
}


