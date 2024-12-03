/*
  The header provides types with detailed description and examples.
*/
#include <cstdint>

extern "C" {
/* 8-bit signed integer type.
 * 
 * A typedef for int8_t providing a consistent naming scheme for 8-bit signed integers.
 * Commonly used for small numeric values where memory efficiency is important.
 * 
 * Range: -128 to 127 ([-2^7, 2^7 - 1])
 * 
 * Correct usage:
 *     i8 volume = -50;         // Audio volume level
 *
 *     i8 temperature = 25;     // Temperature in Celsius
 *
 *     i8 delta = 5;           // Small incremental change
 * 
 * Wrong usage:
 *     i8 largeValue = 500;    // ERROR: Value 500 exceeds i8 range
 *
 *     i8 counter = -200;      // ERROR: Value -200 exceeds i8 range
 *
 *     i8 fileSize = 1024;     // ERROR: Use larger type for file sizes
 */
typedef int8_t i8;

/* 16-bit signed integer type.
 * 
 * A typedef for int16_t providing a consistent naming scheme for 16-bit signed integers.
 * Suitable for medium-range numeric values with moderate memory requirements.
 * 
 * Range: -32,768 to 32,767 ([-2^15, 2^15 - 1])
 * 
 * Correct usage:
 *     i16 altitude = -500;    // Height relative to sea level
 *
 *     i16 rotation = 359;     // Degrees of rotation
 *
 *     i16 year = 2024;       // Current year
 * 
 * Wrong usage:
 *     i16 population = 50000; // ERROR: May exceed range for larger populations
 *
 *     i16 fileOffset = -50000; // ERROR: Use i32/i64 for file operations
 *
 *     i16 colorDepth = 65535; // ERROR: Exceeds i16 range, use u16 instead
 */
typedef int16_t i16;

/* 32-bit signed integer type.
 * 
 * A typedef for int32_t providing a consistent naming scheme for 32-bit signed integers.
 * Commonly used for general-purpose integer arithmetic and array indexing.
 * 
 * Range: -2,147,483,648 to 2,147,483,647 ([-2^31, 2^31 - 1])
 * 
 * Correct usage:
 *     i32 fileSize = 1048576;     // File size in bytes
 *
 *     i32 population = 1000000;    // City population
 *
 *     i32 arrayIndex = 50000;     // Array indexing
 * 
 * Wrong usage:
 *     i32 timestamp = 1674938400000; // ERROR: Unix timestamp in ms exceeds range, use i64
 *
 *     i32 bigData = 3000000000;     // ERROR: Value exceeds i32 range
 *
 *     i32 money = -5000000000;      // ERROR: Large financial values should use i64
 */
typedef int32_t i32;

/* 64-bit signed integer type.
 * 
 * A typedef for int64_t providing a consistent naming scheme for 64-bit signed integers.
 * Used for large numeric values, timestamps, and file sizes.
 * 
 * Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 ([-2^63, 2^63 - 1])
 * 
 * Correct usage:
 *     i64 timestamp = 1674938400000LL;  // Unix timestamp in milliseconds
 *
 *     i64 fileOffset = 1000000000LL;    // Large file position offset
 *
 *     i64 bigCalculation = 5000000000LL; // Large numerical calculations
 * 
 * Wrong usage:
 *     i64 smallValue = 42;              // ERROR: Wasteful for small numbers, use i8/i16
 *
 *     i64 tinyCounter = 100;            // ERROR: Excessive for simple counters
 *
 *     i64 value = 42; // ERROR: Missing LL suffix for large literals
 */
typedef int64_t i64;

/* 8-bit unsigned integer type.
 * 
 * A typedef for uint8_t providing a consistent naming scheme for 8-bit unsigned integers.
 * Commonly used for byte-level operations and small positive values.
 * 
 * Range: 0 to 255 ([0, 2^8 - 1])
 * 
 * Correct usage:
 *     u8 alpha = 255;      // Alpha channel in RGBA
 *
 *     u8 brightness = 128; // LED brightness level
 *
 *     u8 flags = 0x0F;    // Bit flags
 * 
 * Wrong usage:
 *     u8 negative = -1;    // ERROR: Cannot store negative values
 *
 *     u8 large = 300;     // ERROR: Value exceeds range
 *
 *     u8 count = 1000;    // ERROR: Use larger type for bigger counts
 */
typedef uint8_t u8;

/* 16-bit unsigned integer type.
 * 
 * A typedef for uint16_t providing a consistent naming scheme for 16-bit unsigned integers.
 * Suitable for port numbers, flags, and medium-range positive values.
 * 
 * Range: 0 to 65,535 ([0, 2^16 - 1])
 * 
 * Correct usage:
 *     u16 port = 8080;        // Network port number
 *
 *     u16 yearValue = 2024;   // Calendar year
 *
 *     u16 maxUsers = 1000;    // User limit
 * 
 * Wrong usage:
 *     u16 negative = -1;      // ERROR: Cannot store negative values
 *
 *     u16 large = 70000;     // ERROR: Value exceeds range
 *
 *     u16 fileSize = 65536;  // ERROR: Use larger type for file sizes
 */
typedef uint16_t u16;

/* 32-bit unsigned integer type.
 * 
 * A typedef for uint32_t providing a consistent naming scheme for 32-bit unsigned integers.
 * Used for color values, flags, and large positive numbers.
 * 
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 * 
 * Correct usage:
 *     u32 color = 0xFF00FF00;   // RGBA color value
 *
 *     u32 ipAddress = 0x7F000001; // IPv4 address
 *
 *     u32 uniqueId = 1000000;    // ID within range
 * 
 * Wrong usage:
 *     u32 negative = -1;         // ERROR: Cannot store negative values
 *
 *     u32 tooLarge = 5000000000; // ERROR: Value exceeds range
 *
 *     u32 smallValue = 10;       // ERROR: Wasteful for small numbers
 */
typedef uint32_t u32;

/* 64-bit unsigned integer type.
 * 
 * A typedef for uint64_t providing a consistent naming scheme for 64-bit unsigned integers.
 * Used for very large numbers, file sizes, and unique identifiers.
 * 
 * Range: 0 to 18,446,744,073,709,551,615 ([0, 2^64 - 1])
 * 
 * Correct usage:
 *     u64 fileSize = 5000000000ULL;    // Large file size
 *
 *     u64 timestamp = 1674938400000ULL; // High-precision timestamp
 *
 *     u64 uniqueId = 0xFFFFFFFFFFFFULL; // Large unique identifier
 * 
 * Wrong usage:
 *     u64 negative = -1;        // ERROR: Cannot store negative values
 *
 *     u64 smallCount = 42;      // ERROR: Wasteful for small numbers
 *
 *     u64 value = 5000000000;   // ERROR: Missing ULL suffix for large literals
 */
typedef uint64_t u64;

/* 32-bit floating-point type.
 * 
 * A typedef for float providing single-precision floating-point numbers.
 * Suitable for graphics, physics calculations, and general floating-point math.
 * 
 * Range: ±1.18e-38 to ±3.4e38 (IEEE-754 single precision)
 * Precision: ~7 decimal digits
 * 
 * Correct usage:
 *     f32 velocity = 45.67f;    // Object velocity
 *
 *     f32 scale = 0.5f;         // Scaling factor
 *
 *     f32 angle = 3.14159f;    // Trigonometric calculations
 * 
 * Wrong usage:
 *     f32 hugeValue = 1e40f;    // ERROR: Exceeds f32 range, use f64 instead
 *
 *     f32 tinyValue = 1e-40f;  // ERROR: Exceeds f32 precision, use f64 instead
 *
 *     f32 integer = 42;        // ERROR: Use integer types for whole numbers
 */
typedef float f32;

/* 64-bit floating-point type.
 * 
 * A typedef for double providing double-precision floating-point numbers.
 * Used for high-precision calculations and scientific computing.
 * 
 * Range: ±2.23e-308 to ±1.80e308 (IEEE-754 double precision)
 * Precision: ~15-17 decimal digits
 * 
 * Correct usage:
 *     f64 latitude = 51.5074;    // Geographic coordinate
 *
 *     f64 pi = 3.14159265359;    // Mathematical constant
 *
 *     f64 scientificCalc = 1e-300; // High-precision calculations
 * 
 * Wrong usage:
 *     f64 hugeValue = 1e400;     // ERROR: Exceeds f64 range
 *
 *     f64 tinyValue = 1e-400;   // ERROR: Exceeds f64 precision
 *
 *     f64 integer = 42;         // ERROR: Use integer types for whole numbers
 */
typedef double f64;

/* Extended precision floating-point type.
 * 
 * A typedef for long double providing extended precision floating-point numbers.
 * Used for extremely high-precision calculations where accuracy is critical.
 * 
 * Note: Range and precision are platform-dependent
 * Warning: Implementation may vary across different platforms
 * 
 * Correct usage:
 *     f128 scientificCalc = 3.14159265358979323846L;
 *
 *     f128 preciseValue = 1.23456789012345678901L;
 *
 *     f128 highPrecision = 1e-500L; // Extremely high-precision calculations
 * 
 * Wrong usage:
 *     f128 hugeValue = 1e600L;     // ERROR: Exceeds f128 range
 *
 *     f128 tinyValue = 1e-600L;   // ERROR: Exceeds f128 precision
 *
 *     f128 integer = 42L;         // ERROR: Use integer types for whole numbers
 */
typedef long double f128;

/* 8-bit character type.
 * 
 * A typedef for char providing an 8-bit character type.
 * Used for ASCII characters and basic text manipulation.
 * 
 * Range: Platform-dependent signedness (typically -128 to 127 or 0 to 255)
 * Note: Commonly used for ASCII character set
 * 
 * Correct usage:
 *     c8 letter = 'A';          // Single ASCII character
 *
 *     c8 newline = '\n';        // Control character
 *
 *     c8 digit = '5';          // Single digit character
 * 
 * Wrong usage:
 *     c8 nonAscii = 0x80;       // ERROR: Non-ASCII characters may not be supported
 *
 *     c8 wideChar = L'A';       // ERROR: Use wc16 for wide characters
 *
 *     c8 nullChar = NULL;       // ERROR: Use nullptr or 0 for null characters
 */
typedef char c8;

/* Unsigned 8-bit character type.
 * 
 * A typedef for unsigned char providing an unsigned 8-bit character type.
 * Used for unsigned character values and binary data manipulation.
 * 
 * Range: 0 to 255 ([0, 2^8 - 1])
 * 
 * Correct usage:
 *     uc8 byte = 255;      // Single unsigned byte
 *
 *     uc8 pixel = 128;     // Pixel value in an image
 *
 *     uc8 flags = 0x0F;    // Bit flags
 * 
 * Wrong usage:
 *     uc8 negative = -1;    // ERROR: Cannot store negative values
 *
 *     uc8 large = 300;     // ERROR: Value exceeds range
 *
 *     uc8 count = 1000;    // ERROR: Use larger type for bigger counts
 */
typedef unsigned char uc8;

/* Boolean type, 8 bits.
 * 
 * A typedef for bool providing a boolean type.
 * Used for logical operations and conditional statements.
 * 
 * Range: true or false
 * 
 * Correct usage:
 *     b8 isAdmin = true;    // User privilege flag
 *
 *     b8 isValid = false;   // Validation result
 *
 *     b8 enabled = true;    // Feature toggle
 * 
 * Wrong usage:
 *     b8 value = 42;        // ERROR: Use integer types for whole numbers
 *
 *     b8 flag = 0x0F;       // ERROR: Use integer types for bit flags
 *
 *     b8 result = NULL;     // ERROR: Use nullptr or 0 for null values
 */
typedef bool b8;

/* Size type.
 * 
 * A typedef for size_t providing a size type.
 * Used for buffer sizes, array lengths, and memory allocation.
 * 
 * Range: Platform-dependent (typically 0 to 2^32-1 or 0 to 2^64-1)
 * 
 * Correct usage:
 *     sz bufferSize = 1024;    // Buffer size in bytes
 *
 *     sz arrayLength = 100;    // Array length
 *
 *     sz memorySize = 4096;    // Memory allocation size
 * 
 * Wrong usage:
 *     sz negative = -1;        // ERROR: Cannot store negative values
 *
 *     sz hugeValue = 5000000000; // ERROR: Value may exceed range
 *
 *     sz smallValue = 10;      // ERROR: Wasteful for small numbers
 */
typedef size_t sz;

/* Pointer difference type.
 * 
 * A typedef for ptrdiff_t providing a pointer difference type.
 * Used for pointer arithmetic and array indexing.
 * 
 * Range: Platform-dependent (typically -2^31 to 2^31-1 or -2^63 to 2^63-1)
 * 
 * Correct usage:
 *     pdiff offset = 10;    // Pointer offset
 *
 *     pdiff stride = 4;     // Array stride
 *
 *     pdiff index = 100;    // Array indexing
 * 
 * Wrong usage:
 *     pdiff hugeValue = 5000000000; // ERROR: Value may exceed range
 *
 *     pdiff smallValue = 10;      // ERROR: Wasteful for small numbers
 *
 *     pdiff pointer = 0x10000000; // ERROR: Use pointer types for pointers
 */
typedef ptrdiff_t pdiff;

/* Pointer integer type.
 * 
 * A typedef for intptr_t providing a pointer integer type.
 * Used for storing pointer values as integers.
 * 
 * Range: Platform-dependent (typically -2^31 to 2^31-1 or -2^63 to 2^63-1)
 * 
 * Correct usage:
 *     iptr pointerValue = reinterpret_cast<iptr>(ptr);
 *
 *     iptr address = 0x10000000;
 *
 *     iptr offset = 100;Me

add space after each line of correct and wrong code
 * 
 * Wrong usage:
 *     iptr hugeValue = 5000000000; // ERROR: Value may exceed range
 *
 *     iptr smallValue = 10;      // ERROR: Wasteful for small numbers
 *
 *     iptr nonPointer = 42;      // ERROR: Use integer types for non-pointer values
 */
typedef intptr_t iptr;

/* Unsigned pointer type.
 * 
 * A typedef for uintptr_t providing an unsigned pointer type.
 * Used for storing pointer values as unsigned integers.
 * 
 * Range: Platform-dependent (typically 0 to 2^32-1 or 0 to 2^64-1)
 * 
 * Correct usage:
 *     uptr pointerValue = reinterpret_cast<uptr>(ptr);
 *
 *     uptr address = 0x10000000;
 *
 *     uptr offset = 100;
 * 
 * Wrong usage:
 *     uptr hugeValue = 5000000000; // ERROR: Value may exceed range
 *
 *     uptr smallValue = 10;      // ERROR: Wasteful for small numbers
 *
 *     uptr nonPointer = 42;      // ERROR: Use integer types for non-pointer values
 */
typedef uintptr_t uptr;

/* Wide character type, 16 bits.
 * 
 * A typedef for wchar_t providing a wide character type.
 * Used for Unicode characters and internationalization.
 * 
 * Range: Platform-dependent (typically 0 to 65,535)
 * 
 * Correct usage:
 *     wc16 character = L'A';    // Wide character
 *
 *     wc16 string[] = L"Hello"; // Wide string
 *
 *     wc16 unicode = 0x20AC;   // Unicode character
 * 
 * Wrong usage:
 *     wc16 nonUnicode = 0x80;   // ERROR: Non-Unicode characters may not be supported
 *
 *     wc16 ascii = 'A';         // ERROR: Use c8 for ASCII characters
 *
 *     wc16 nullChar = NULL;     // ERROR: Use nullptr or 0 for null characters
 */
typedef wchar_t wc16;

/* 16-bit character type.
 * 
 * A typedef for char16_t providing a 16-bit character type.
 * Used for UTF-16 encoded strings and Unicode characters.
 * 
 * Range: 0 to 65,535 ([0, 2^16 - 1])
 * 
 * Correct usage:
 *     c16 character = u'A';    // 16-bit character
 *
 *     c16 string[] = u"Hello"; // UTF-16 encoded string
 *
 *     c16 unicode = 0x20AC;   // Unicode character
 * 
 * Wrong usage:
 *     c16 nonUnicode = 0x80;   // ERROR: Non-Unicode characters may not be supported
 *
 *     c16 ascii = 'A';         // ERROR: Use c8 for ASCII characters
 *
 *     c16 nullChar = NULL;     // ERROR: Use nullptr or 0 for null characters
 */
typedef char16_t c16;

/* 32-bit character type.
 * 
 * A typedef for char32_t providing a 32-bit character type.
 * Used for UTF-32 encoded strings and Unicode characters.
 * 
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 * 
 * Correct usage:
 *     c32 character = U'A';    // 32-bit character
 *
 *     c32 string[] = U"Hello"; // UTF-32 encoded string
 *
 *     c32 unicode = 0x20AC;   // Unicode character
 * 
 * Wrong usage:
 *     c32 nonUnicode = 0x80;   // ERROR: Non-Unicode characters may not be supported
 *
 *     c32 ascii = 'A';         // ERROR: Use c8 for ASCII characters
 *
 *     c32 nullChar = NULL;     // ERROR: Use nullptr or 0 for null characters
 */
typedef char32_t c32;

/* Signed 32-bit integer type.
 * 
 * A typedef for long providing a signed 32-bit integer type.
 * Used for general-purpose integer arithmetic and array indexing.
 * 
 * Range: -2,147,483,648 to 2,147,483,647 ([-2^31, 2^31 - 1])
 * 
 * Correct usage:
 *     l32 fileSize = 1048576L;     // File size in bytes
 *
 *     l32 population = 1000000L;    // City population
 *
 *     l32 arrayIndex = 50000L;     // Array indexing
 * 
 * Wrong usage:
 *     l32 timestamp = 1674938400000; // ERROR: Unix timestamp in ms exceeds range, use i64
 *
 *     l32 bigData = 3000000000;     // ERROR: Value exceeds l32 range
 *
 *     l32 money = -5000000000;      // ERROR: Large financial values should use i64
 */
typedef long l32;

/* Unsigned 32-bit integer type.
 * 
 * A typedef for unsigned long providing an unsigned 32-bit integer type.
 * Used for color values, flags, and large positive numbers.
 * 
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 * 
 * Correct usage:
 *     ul32 color = 0xFF00FF00UL;   // RGBA color value
 *
 *     ul32 ipAddress = 0x7F000001UL; // IPv4 address
 *
 *     ul32 uniqueId = 1000000UL;    // ID within range
 * 
 * Wrong usage:
 *     ul32 negative = -1;         // ERROR: Cannot store negative values
 *
 *     ul32 tooLarge = 5000000000; // ERROR: Value exceeds range
 *
 *     ul32 smallValue = 10;       // ERROR: Wasteful for small numbers
 */
typedef unsigned long ul32;

/* Signed 64-bit integer type.
 * 
 * A typedef for long long providing a signed 64-bit integer type.
 * Used for large numeric values, timestamps, and file sizes.
 * 
 * Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 ([-2^63, 2^63 - 1])
 * 
 * Correct usage:
 *     ll64 timestamp = 1674938400000LL;  // Unix timestamp in milliseconds
 *
 *     ll64 fileOffset = 1000000000LL;    // Large file position offset
 *
 *     ll64 bigCalculation = 5000000000LL; // Large numerical calculations
 * 
 * Wrong usage:
 *     ll64 smallValue = 42;              // ERROR: Wasteful for small numbers, use i8/i16
 *
 *     ll64 tinyCounter = 100;            // ERROR: Excessive for simple counters
 *
 *     ll64 value = 42; // ERROR: Missing LL suffix for large literals
 */
typedef long long ll64;

/* Unsigned 64-bit integer type.
 * 
 * A typedef for unsigned long long providing an unsigned 64-bit integer type.
 * Used for very large numbers, file sizes, and unique identifiers.
 * 
 * Range: 0 to 18,446,744,073,709,551,615 ([0, 2^64 - 1])
 * 
 * Correct usage:
 *     ull64 fileSize = 4294967296ULL;    // Large file size in bytes
 *
 *     ull64 uniqueId = 123456789ULL;     // Unique identifier
 *
 *     ull64 bigData = 5000000000ULL;     // Large numerical values
 * 
 * Wrong usage:
 *     ull64 negative = -1;        // ERROR: Cannot store negative values
 *
 *     ull64 smallCount = 42;      // ERROR: Wasteful for small numbers
 *
 *     ull64 value = 5000000000;   // ERROR: Missing ULL suffix for large literals
 */
typedef unsigned long long ull64;

}