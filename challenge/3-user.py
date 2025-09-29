#!/usr/bin/env python3
"""
Fix: ensure password is stored hashed and validation compares hash(password)
to stored hash. Keep a tiny demo that prints nothing if all tests pass.
"""
import hashlib
from typing import Optional

class User:
    def __init__(self) -> None:
        self.__password_hash: Optional[str] = None

    @staticmethod
    def __encrypt(password: str) -> str:
        # simple, deterministic hashing (no external deps)
        return hashlib.sha256(password.encode('utf-8')).hexdigest()

    def set_password(self, password: Optional[str]) -> None:
        if isinstance(password, str):
            self.__password_hash = self.__encrypt(password)
        else:
            self.__password_hash = None

    def is_valid_password(self, password: Optional[str]) -> bool:
        if self.__password_hash is None or not isinstance(password, str):
            return False
        return self.__password_hash == self.__encrypt(password)

if __name__ == "__main__":
    # tests: should print nothing if all good
    print("Test User")
    u = User()
    u.set_password("Holberton")
    # Must be True for correct password
    if not u.is_valid_password("Holberton"):
        print("is_valid_password should return True if it's the right password")
