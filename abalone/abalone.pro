TEMPLATE = subdirs

SUBDIRS += \
    metier \
    console \
    gui \
    tests

OTHER_FILES += \
    defaults.pri

# CONFIG += ordered

# where to find de sub projects - give the folders
metier.subdir = metier
console.subdir = console
gui.subdir = gui
tests.subdir = tests

# what subproject depends on others
console.depends = metier
gui.depends = metier
tests.depends = metier
