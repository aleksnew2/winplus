/*
  The header provides types with detailed description and examples.
*/
#include <cstdint>
#include <string>

/* 8-bit signed integer type.
 *
 * A typedef for int8_t providing a consistent naming scheme for 8-bit signed
 * integers. Commonly used for small numeric values where memory efficiency is
 * important.
 *
 * Range: -128 to 127 ([-2^7, 2^7 - 1])
 */
typedef int8_t i8;

/* 16-bit signed integer type.
 *
 * A typedef for int16_t providing a consistent naming scheme for 16-bit signed
 * integers. Suitable for medium-range numeric values with moderate memory
 * requirements.
 *
 * Range: -32,768 to 32,767 ([-2^15, 2^15 - 1])
 */
typedef int16_t i16;

/* 32-bit signed integer type.
 *
 * A typedef for int32_t providing a consistent naming scheme for 32-bit signed
 * integers. Commonly used for general-purpose integer arithmetic and array
 * indexing.
 *
 * Range: -2,147,483,648 to 2,147,483,647 ([-2^31, 2^31 - 1])
 */
typedef int32_t i32;

/* 64-bit signed integer type.
 *
 * A typedef for int64_t providing a consistent naming scheme for 64-bit signed
 * integers. Used for large numeric values, timestamps, and file sizes.
 *
 * Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 ([-2^63, 2^63 - 1])
 */
typedef int64_t i64;

/* 8-bit unsigned integer type.
 *
 * A typedef for uint8_t providing a consistent naming scheme for 8-bit unsigned
 * integers. Commonly used for byte-level operations and small positive values.
 *
 * Range: 0 to 255 ([0, 2^8 - 1])
 */
typedef uint8_t u8;

/* 16-bit unsigned integer type.
 *
 * A typedef for uint16_t providing a consistent naming scheme for 16-bit
 * unsigned integers. Suitable for port numbers, flags, and medium-range
 * positive values.
 *
 * Range: 0 to 65,535 ([0, 2^16 - 1])
 */
typedef uint16_t u16;

/* 32-bit unsigned integer type.
 *
 * A typedef for uint32_t providing a consistent naming scheme for 32-bit
 * unsigned integers. Used for color values, flags, and large positive numbers.
 *
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 */
typedef uint32_t u32;

/* 64-bit unsigned integer type.
 *
 * A typedef for uint64_t providing a consistent naming scheme for 64-bit
 * unsigned integers. Used for very large numbers, file sizes, and unique
 * identifiers.
 *
 * Range: 0 to 18,446,744,073,709,551,615 ([0, 2^64 - 1])
 */
typedef uint64_t u64;

/* 32-bit floating-point type.
 *
 * A typedef for float providing single-precision floating-point numbers.
 * Suitable for graphics, physics calculations, and general floating-point math.
 *
 * Range: ±1.18e-38 to ±3.4e38 (IEEE-754 single precision)
 * Precision: ~7 decimal digits
 */
typedef float f32;

/* 64-bit floating-point type.
 *
 * A typedef for double providing double-precision floating-point numbers.
 * Used for high-precision calculations and scientific computing.
 *
 * Range: ±2.23e-308 to ±1.80e308 (IEEE-754 double precision)
 * Precision: ~15-17 decimal digits
 */
typedef double f64;

/* Extended precision floating-point type.
 *
 * A typedef for long double providing extended precision floating-point
 * numbers. Used for extremely high-precision calculations where accuracy is
 * critical.
 *
 * Note: Range and precision are platform-dependent
 * Warning: Implementation may vary across different platforms
 */
typedef long double f128;

/* 8-bit character type.
 *
 * A typedef for char providing an 8-bit character type.
 * Used for ASCII characters and basic text manipulation.
 *
 * Range: Platform-dependent signedness (typically -128 to 127 or 0 to 255)
 * Note: Commonly used for ASCII character set
 */
typedef char c8;

/* Unsigned 8-bit character type.
 *
 * A typedef for unsigned char providing an unsigned 8-bit character type.
 * Used for unsigned character values and binary data manipulation.
 *
 * Range: 0 to 255 ([0, 2^8 - 1])
 */
typedef unsigned char uc8;

/* Boolean type, 8 bits.
 *
 * A typedef for bool providing a boolean type.
 * Used for logical operations and conditional statements.
 *
 * Range: true or false
 */
typedef bool b8;

/* Size type.
 *
 * A typedef for size_t providing a size type.
 * Used for buffer sizes, array lengths, and memory allocation.
 *
 * Range: Platform-dependent (typically 0 to 2^32-1 or 0 to 2^64-1)
 */
typedef size_t sz;

/* Pointer difference type.
 *
 * A typedef for ptrdiff_t providing a pointer difference type.
 * Used for pointer arithmetic and array indexing.
 *
 * Range: Platform-dependent (typically -2^31 to 2^31-1 or -2^63 to 2^63-1)
 */
typedef ptrdiff_t pdiff;

/* Pointer integer type.
 *
 * A typedef for intptr_t providing a pointer integer type.
 * Used for storing pointer values as integers.
 *
 * Range: Platform-dependent (typically -2^31 to 2^31-1 or -2^63 to 2^63-1)
 */
typedef intptr_t iptr;

/* Unsigned pointer type.
 *
 * A typedef for uintptr_t providing an unsigned pointer type.
 * Used for storing pointer values as unsigned integers.
 *
 * Range: Platform-dependent (typically 0 to 2^32-1 or 0 to 2^64-1)
 */
typedef uintptr_t uptr;

/* Standard string type.
 *
 * A typedef for std::string providing a standard string type.
 * Used for text manipulation, string storage, and string operations.
 * Manages dynamic character arrays with automatic memory handling.
 */
typedef std::string string;

/* 16-bit character type.
 *
 * A typedef for char16_t providing a 16-bit character type.
 * Used for UTF-16 encoded strings and Unicode characters.
 *
 * Range: 0 to 65,535 ([0, 2^16 - 1])
 */
typedef char16_t c16;

/* 32-bit character type.
 *
 * A typedef for char32_t providing a 32-bit character type.
 * Used for UTF-32 encoded strings and Unicode characters.
 *
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 */
typedef char32_t c32;

/* Signed 32-bit integer type.
 *
 * A typedef for long providing a signed 32-bit integer type.
 * Used for general-purpose integer arithmetic and array indexing.
 *
 * Range: -2,147,483,648 to 2,147,483,647 ([-2^31, 2^31 - 1])
 */
typedef long l32;

/* Unsigned 32-bit integer type.
 *
 * A typedef for unsigned long providing an unsigned 32-bit integer type.
 * Used for color values, flags, and large positive numbers.
 *
 * Range: 0 to 4,294,967,295 ([0, 2^32 - 1])
 */
typedef unsigned long ul32;

/* Signed 64-bit integer type.
 *
 * A typedef for long long providing a signed 64-bit integer type.
 * Used for large numeric values, timestamps, and file sizes.
 *
 * Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 ([-2^63, 2^63 - 1])
 */
typedef long long ll64;

/* Unsigned 64-bit integer type.
 *
 * A typedef for unsigned long long providing an unsigned 64-bit integer type.
 * Used for very large numbers, file sizes, and unique identifiers.
 *
 * Range: 0 to 18,446,744,073,709,551,615 ([0, 2^64 - 1])
 */
typedef unsigned long long ull64;
