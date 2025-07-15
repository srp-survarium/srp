int __thiscall vostok::render::statistics_value<int>::average(vostok::render::statistics_value<int> *this)
{
  int v1; // eax
  int *history; // ecx
  int v3; // edx

  v1 = 0;
  history = this->history;
  v3 = 16;
  do
  {
    v1 += *history++;
    --v3;
  }
  while ( v3 );
  return v1 / 16;
}


void __usercall vostok::render::statistics_value<double>::average(
        vostok::render::statistics_value<double> *this@<ecx>,
        int a2@<eax>)
{
  double v2; // xmm0_8
  double *v3; // eax
  int v4; // ecx
  double v5; // xmm1_8

  v2 = 0.0;
  v3 = (double *)(a2 + 200);
  v4 = 16;
  do
  {
    v5 = *v3++;
    --v4;
    v2 = v5 + v2;
  }
  while ( v4 );
}
