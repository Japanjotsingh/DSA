class Solution(object):
    def simplifyPath(self, path):
        stack = []
        for i in path.split('/'):
            if stack and  i == '..':
                stack.pop()
            elif i not in ['.' , '..' , '']:
                stack.append(i)
        return '/'+'/'.join(stack) 