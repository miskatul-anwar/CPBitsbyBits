import math

# Function to calculate the total distance Husam walked
def calculate_total_distance(a, b, c, x):
    # Distance from home to river
    distance_home_to_river = c
    
    # Distance from river to grandmother's home
    distance_river_to_grandmother = math.sqrt(a**2 + (b + c)**2)
    
    # Distance from grandmother's home to home
    distance_grandmother_to_home = math.sqrt(a**2 + b**2)
    
    # Distance Husam walked before remembering to fill his bottle
    distance_walked_before_river = (x / 100) * distance_grandmother_to_home
    
    # Remaining distance from that point to the river
    remaining_distance_to_river = math.sqrt((a - (x / 100) * a)**2 + (b - (x / 100) * b + c)**2)
    
    # Total distance Husam walked
    total_distance = (distance_home_to_river +
                      distance_river_to_grandmother +
                      distance_walked_before_river +
                      remaining_distance_to_river +
                      c)
    
    # Set precision to 9 decimal places
    total_distance = round(total_distance, 9)
    
    return total_distance

# Input values
a = float(input())
b = float(input())
c = float(input())
x = float(input())

# Calculate total distance
total_distance = calculate_total_distance(a, b, c, x)

# Output the result
print(f"{total_distance:.9f} kilometers")

