g++ src/lms.cpp \
    src/components/telemetreringsmodul/telemetreringsmodul.cpp \
    src/components/indikatorpanel/indikatorpanel.cpp \
    src/components/manoverpanel/manoverpanel.cpp \
    src/components/styr_och_logikenhet/sol.cpp \
    src/components/databussadapter/databussadapter.cpp \
    src/components/datastav/datastav.cpp \
    -I src/interfaces \
    -I src/components/databussadapter \
    -I src/components/datastav \
    -I src/components/styr_och_logikenhet \
    -I src/components/manoverpanel \
    -I src/components/indikatorpanel \
    -I src/components/telemetreringsmodul \
    -o bin/lms
