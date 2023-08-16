import numpy as np

def calculate_average(arr):
    print('Python: calculate_average()')
    return np.mean(arr)

def main():
    # Generate an array of 7 elements
    array = (1, 2, 5, 10, 17)
    print("Generated Array:", array)

    # Calculate and print the average using the calculate_average function
    avg = calculate_average(array)
    print("Average:", avg)

if __name__ == "__main__":
    main()
