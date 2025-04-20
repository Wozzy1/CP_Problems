# largest palindrome product from two 2 digit numbers

def multiply():
    num1 = 0
    num2 = 0
    maxNum = -1
    while num1 < 1000:
        num2 = 0
        while num2 < 1000:
            product = num1 * num2
            # print(num1, num2, product)
            if (isPalindrome(str(product))):
                if product >= maxNum:
                    maxNum = product
            num2 += 1
            
        num1 += 1

    return maxNum

def isPalindrome(string):
    return isPalindromeCode(string, 0, len(string)-1)

def isPalindromeCode(string, start, end):
    if start == end:
        return True

    if string[start] != string[end]:
        return False
    
    if start < end + 1:
        return isPalindromeCode(string, start+1, end-1)

    return True

print(multiply())