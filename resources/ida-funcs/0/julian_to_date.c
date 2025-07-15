void __cdecl julian_to_date(int *y, int *m, int *d)
{
  int v3; // ecx
  char *v4; // ecx
  int v5; // edi
  char *v6; // ecx
  int v7; // ebx
  char *v8; // ecx
  int v9; // esi

  v4 = (char *)&unk_10BD9 + v3;
  v5 = 4 * (int)v4 / 146097;
  v6 = &v4[(146097 * v5 + 3) / -4];
  v7 = 4000 * (int)(v6 + 1) / 1461001;
  v8 = &v6[31 - 1461 * v7 / 4];
  v9 = 80 * (int)v8 / 2447;
  *d = (int)&v8[-(2447 * v9 / 80)];
  *m = v9 - 12 * (v9 / 11) + 2;
  *y = v9 / 11 + v7 + 100 * (v5 - 49);
}
