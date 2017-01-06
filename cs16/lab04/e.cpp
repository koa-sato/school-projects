double dfactorial (int x) {
  if (x == 0)
    return 1;
  return x * dfactorial(x-1);
}