# Chunk

Here I will document infos on chunks, so I won't forget them.

## Chunk Layout

### Length

4 byte unsigned int. Gives Number of Bytes in the Chunks field.
Counts **only** the the [Data Field](#chunk-data), **not** [itself](#length)
the Chunk [Type](#chunk-type) Code or the [CRC](#crc). Zero is a valid length.

### Chunk Type

4 byte Chunk Type Code. E.g. "IDAT". The Types consist of uppercase and lowercase letters.

### Chunk Data

The Data Bytes belonging to the Chunk Type. Can be zero Length.

### CRC

The 4 byte CRC or Cyclic Redundancy Check, is used to Calculate, if the Chunk is still valid.
It is always present, even if the Chunk is zero length.
See [CRC Algorithm](http://www.libpng.org/pub/png/spec/1.2/PNG-Structure.html#CRC-algorithm)

### Most Important

The minimum Length of a Chunk is 12 Bytes; 4byte length + 4byte type + 4byte CRC.

