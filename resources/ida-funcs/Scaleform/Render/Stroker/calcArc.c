void __userpurge Scaleform::Render::Stroker::calcArc(
        Scaleform::Render::Stroker *this@<ecx>,
        Scaleform::Render::TessBase *tess,
        float x,
        _DWORD *y,
        float dx1,
        float dy1,
        float dx2,
        float dy2,
        float a9,
        float a10)
{
  double v11; // st7
  double v12; // st6
  double v13; // st6
  double v14; // st5
  int v15; // ebx
  float v16; // [esp+14h] [ebp-18h]
  float v17; // [esp+1Ch] [ebp-10h]
  float v18; // [esp+1Ch] [ebp-10h]
  float v19; // [esp+28h] [ebp-4h]
  float v20; // [esp+28h] [ebp-4h]
  float retaddr; // [esp+2Ch] [ebp+0h]
  float v22; // [esp+30h] [ebp+4h]
  float v23; // [esp+30h] [ebp+4h]
  float v24; // [esp+30h] [ebp+4h]
  float v25; // [esp+40h] [ebp+14h]
  float v26; // [esp+40h] [ebp+14h]
  float v27; // [esp+48h] [ebp+1Ch]
  float v28; // [esp+48h] [ebp+1Ch]
  float v29; // [esp+48h] [ebp+1Ch]
  float v30; // [esp+48h] [ebp+1Ch]
  float v31; // [esp+48h] [ebp+1Ch]
  float v32; // [esp+48h] [ebp+1Ch]

  v22 = atan2(dy1, dx1);
  v19 = v22;
  v23 = atan2(a10, a9);
  retaddr = this->Width / (this->CurveTolerance * 0.25 + this->Width);
  retaddr = acos(retaddr);
  retaddr = retaddr + retaddr;
  v27 = dy1 + dy2;
  v17 = v27;
  v28 = dx1 + dx2;
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*y + 16))(y, LODWORD(v28), LODWORD(v17));
  v11 = v19;
  v12 = v23;
  if ( v23 < (double)v19 )
  {
    v24 = v12 + 6.283185482025146;
    v12 = v24;
  }
  v13 = v12 - v11;
  v14 = v13 / retaddr;
  retaddr = v13 / (double)((int)v14 + 1);
  v20 = v11 + retaddr;
  if ( (int)v14 > 0 )
  {
    v15 = (int)v14;
    do
    {
      v29 = sin(v20);
      v30 = v29 * this->Width + dy1;
      v16 = v30;
      v31 = cos(v20);
      v32 = v31 * this->Width + dx1;
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*y + 16))(y, LODWORD(v32), LODWORD(v16));
      --v15;
      v20 = retaddr + v20;
    }
    while ( v15 );
  }
  v25 = dy1 + a10;
  v18 = v25;
  v26 = dx1 + a9;
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*y + 16))(y, LODWORD(v26), LODWORD(v18));
}
