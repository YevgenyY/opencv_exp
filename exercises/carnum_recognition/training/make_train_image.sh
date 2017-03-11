#!/bin/sh

# Create text <-> image pair
text2image --text=./training_text.txt --outputbase=eng.RoadNumbers.ex0 --font='RoadNumbers' --fonts_dir=./font/v2

# Train tesseract
tesseract eng.RoadNumbers.ex0.tif eng.RoadNumbers.ex0 box.train

# Run unicharset extractor
unicharset_extractor eng.RoadNumbers.ex0.box lang.fontname.ex1.box

# Make final (output) unicharset
mftraining -F font_properties -U unicharset -O eng.unicharset eng.RoadNumbers.ex0.tr

# Make finel dataset for OCR
combine_tessdata eng


