void __thiscall Scaleform::GFx::Stream::ReadRect(Scaleform::GFx::Stream *this, Scaleform::Render::Rect<float> *pr)
{
  int UInt; // esi
  int v4; // eax
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+18h] [ebp+4h]
  int v12; // [esp+18h] [ebp+4h]
  int v13; // [esp+18h] [ebp+4h]

  this->UnusedBits = 0;
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 5);
  v4 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  v5 = 1 << (UInt - 1);
  v10 = v4;
  if ( (v5 & v4) != 0 )
    v10 = (-1 << UInt) | v4;
  pr->x1 = (float)v10;
  v7 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  v11 = v7;
  if ( (v5 & v7) != 0 )
    v11 = (-1 << UInt) | v7;
  pr->x2 = (float)v11;
  v8 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  v12 = v8;
  if ( (v5 & v8) != 0 )
    v12 = (-1 << UInt) | v8;
  pr->y1 = (float)v12;
  v9 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  v13 = v9;
  if ( (v5 & v9) != 0 )
    v13 = (-1 << UInt) | v9;
  pr->y2 = (float)v13;
}
