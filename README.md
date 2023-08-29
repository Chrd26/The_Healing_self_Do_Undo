# The_Healing_self_Do_Undo
This is my first project. The project is based on a book by Deepak Chopra named The Healing Self. The aim of this app is to generate random Do and Undo recommendations for each day.

# What is happening in the app

When the application runs for the first time during the day, random selections for the 2 suggestions are made. One selection to do and one selection to undo. Then, the selections and
The current day is saved in a file.
Then, the application shows the 2 file entries in the application window. The same selection will appear again and again until the day that is saved in the file is different
than the local day.

# Building

To build the application, run the following command:

It should work when GCC is installed on Linux and MacOS. On windows, mingGW is needed.

```
g++ ui.cpp -o app `wx-config --libs` `wx-config --cxxflags` \address-to-boost's-system.a-file \address-to-boost's-serialization.a-file
```

