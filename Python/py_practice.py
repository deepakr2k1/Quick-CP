print("HELLO PYTHON")
# print('o----')
# print(' ||||')
# print('$' * 3)
# price = 100
# print(price)
# rating = 4.5
# is_published = True
# if is_published:
#     print(rating)

# # Practice Problem 1
# name ='John Smith'
# age = 20
# is_new = True
# if is_new:
#     print(name,age)

# # INPUT
# name = input('What is Your name ')
# print('Hi ' + name)

# birth_year = input('Birth Year: ')      # Input is taken always string
# age = 2020-int(birth_year)
# print(age)

# # course = 'Python's Course for beginners
# course = "Python's Course for beginners"
# print(course)
# course = '''Hi,

# This is me Deepak '''
# print(course)

# course = "Python's Course for beginners"
# print(course[0],course[1],course[-1],course[-2])
# print(course[0:3])
# print(course[4:])
# print(course[:8])
# print(course[1:-2])

# first = 'John'
# last = 'Smith'
# # msg = first + ' [' + last + '] is Coder'
# msg = f'{first} [{last}] is a coder'            # formatted string
# print(msg)

# course = "Python Course for beginners"
# print(len(course))
# print(course.lower())
# print(course.find('o'))
# print(course.replace('beginners','Absolute'))
# print('Python' in course)
# print(course.title())

# print(5*3)
# print(5**3)
# x = 10+3*2      # order precedence exponential(5**3), mul/div, add/sub
# print(x)
# print(round(2.7))

# import math
# print(math.floor(2.9))

# is_hot = False
# is_cold = True
# if is_hot:
#     print("It's a hot day")
# elif is_cold:
#     print("It's a cold day")
# else:
#      print("It's a Lovely day")

# cond1 = False
# cond2 = False
# if cond1 & cond2:
#     print("Both True")
# elif cond1 | cond2:
#     print("One is True")
# else :
#     print("Both False")

# i=1
# while i<=5 :
#     print('$'*i)
#     i+=1
# print("DONE")

# for item in 'Python' :
#     print(item)

# for item in ['Python','is','used','for','ML'] :
#     print(item)

# for i in range(10,16,2) :
#     print(i)

# array = [3,6,8,7,10,6]
# print(array)

# matrix = [
#     [1,2,3],
#     [4,5,6],
#     [7,8,9]
# ]
# print(matrix)

# array = [3,6,8,7,10,6]
# array.append(20)
# array.insert(2,100)
# array.remove(7)
# print(array)
# print(array.index(6))

# coordinates = (1,2,3)
# print(coordinates)
# x,y,z = coordinates
# print(y)

# # Key Value Pair
# customer  = {
#     "name" : "John",
#     "age" : 30,
#     "is_verified" : True
# }
# print(customer["name"])

# def greet_user(name) :      # name is a parameter
#     print('Hi ' + name)

# greet_user('John')          # John is an arguement

# try:
#     age = int(input('Age: '))
#     print(age)
# except ValueError:
#     print('INVALID VALUE')