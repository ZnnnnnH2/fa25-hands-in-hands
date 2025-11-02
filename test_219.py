import subprocess
import sys

test_cases = [
    ("+\n998877665544332211\n11223344556677", "998888888888888888"),
    ("-\n-8776655443322\n-91223344556677", "82446689113355"),
    ("+\n998877665544332211\n112233445566778899", "1111111111111111110"),
]

print("Testing 219.cpp...")

for i, (input_data, expected) in enumerate(test_cases, 1):
    print(f"\nTest case {i}:")
    print(f"Input: {repr(input_data)}")
    print(f"Expected: {expected}")

    try:
        result = subprocess.run(
            ['./219.exe'],
            input=input_data,
            capture_output=True,
            text=True,
            timeout=5
        )

        output = result.stdout.strip()
        print(f"Got: {output}")

        if output == expected:
            print("PASS")
        else:
            print("FAIL")

    except FileNotFoundError:
        print("ERROR: 219.exe not found. Please compile first.")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: {e}")
