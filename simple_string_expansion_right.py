def str_num(s):
    digit_ = ''
    str_ = ''
    for elem in s:
        if elem.isdigit():
            digit_+= elem
        else:
            str_ += elem
    return (str_, int(digit_) if digit_ != '' else '')

def solve(string):
    pos = string.find(')')
    list_exp = string[:pos].split('(')
    list_exp.reverse()
    ans = ''
    for idx, expr in enumerate(list_exp):
        if(idx == 0):
            ans += expr
        else:
            substr, times = str_num(expr) 
            if(times != ''):
                ans = ans * times
                ans = substr + ans
            else:
                ans = substr + ans
    return ans, list_exp