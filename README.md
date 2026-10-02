# Disk And Memory Eater (dame)

Small Linux utility for stress-testing disk and memory usage. It intentionally allocates files and RAM until it is interrupted with Ctrl+C.

> Note: the memory-eating modes are intentionally leaky and are designed for test workloads, not for long-lived production use.

## Build

```bash
make
```

## Usage by mode

### `ed`

Fill disk space in a target directory without a size limit.

```bash
./dame ed /tmp/test-dir
```

### `edl`

Fill disk space up to a specific limit.

```bash
./dame edl /tmp/test-dir 512 m
```

This writes up to 512 MiB in the target directory.

### `em`

Fill memory without a limit until interrupted.

```bash
./dame em
```

### `eml`

Fill memory up to a specific limit.

```bash
./dame eml 256 m
```

This allocates up to 256 MiB of memory.

### `edlr`

Fill disk space up to a size limit and write at a given rate.

```bash
./dame edlr /tmp/test-dir 1 k d 1 k
```

This means: write up to 1 KiB in the target directory, at a rate of 1 KiB per day.

## Size units

- `b`: bytes
- `k`: kilobytes
- `m`: megabytes
- `g`: gigabytes

## `edlr` arguments

```bash
./dame edlr <path> <limit> <limit_unit> <timeopt> <rate> <rate_unit>
```

Time options:

- `s`: second
- `m`: minute
- `h`: hour
- `d`: day

## Notes

- This tool is intentionally destructive and should only be used on disposable test targets.
- It is designed for Linux systems and is not meant to be a general-purpose utility.
- Use Ctrl+C to stop the process.

