HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileA("CONIN$", 0xC0000000, 3u, 0, 3u, 0, 0);
  _coninpfh = result;
  return result;
}
