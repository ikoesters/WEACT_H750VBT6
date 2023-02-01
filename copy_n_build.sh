#!/bin/sh

UPY_DIR="../micropython/Micropython_Vanilla/micropython"
BOARDNAME="WEACT_H750VBT6"
COPY_FILES="mpconfigboard.mk,mpconfigboard.h,pins.csv"

cp {$COPY_FILES} $UPY_DIR/ports/stm32/boards/$BOARDNAME
cd $UPY_DIR/ports/stm32
rm -rf build-$BOARDNAME
make BOARD=$BOARDNAME
