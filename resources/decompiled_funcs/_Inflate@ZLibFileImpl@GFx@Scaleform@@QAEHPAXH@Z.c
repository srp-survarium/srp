int __thiscall Scaleform::GFx::ZLibFileImpl::Inflate(
        Scaleform::GFx::ZLibFileImpl *this,
        unsigned __int8 *dst,
        int bytes)
{
  int UserPos; // eax
  int LogicalStreamPos; // ecx
  signed int v6; // edi
  int v7; // ecx
  signed int v8; // ebp
  int BacktrackTail; // edx
  signed int v10; // eax
  unsigned int v11; // edi
  unsigned __int8 *v12; // ebx
  signed int v13; // edi
  signed int v15; // ebp
  int BacktrackSize; // eax
  int v17; // eax
  int backtrackDataPos; // [esp+10h] [ebp-8h]
  int backtrackDataPosa; // [esp+10h] [ebp-8h]
  int backtrackDataSave; // [esp+14h] [ebp-4h]

  UserPos = this->UserPos;
  LogicalStreamPos = this->LogicalStreamPos;
  v6 = bytes;
  backtrackDataPos = 0;
  if ( UserPos >= LogicalStreamPos )
  {
    v12 = dst;
  }
  else
  {
    v7 = LogicalStreamPos - UserPos;
    backtrackDataPosa = v7;
    v8 = bytes;
    if ( v7 <= bytes )
      v8 = v7;
    BacktrackTail = this->BacktrackTail;
    v10 = v8;
    backtrackDataSave = v8;
    if ( v7 <= BacktrackTail )
    {
      v12 = dst;
    }
    else
    {
      v11 = v7 - BacktrackTail;
      if ( v7 - BacktrackTail > v8 )
        v11 = v8;
      memcpy(dst, &this->BacktrackBuffer[BacktrackTail + this->BacktrackSize - v7], v11);
      v10 = v8;
      v7 = backtrackDataPosa - v11;
      v8 -= v11;
      v12 = &dst[v11];
      v6 = bytes;
    }
    if ( v8 > 0 )
    {
      memcpy(v12, &this->BacktrackBuffer[this->BacktrackTail - v7], v8);
      v10 = backtrackDataSave;
      v6 = bytes;
      v12 += v8;
    }
    v6 -= v10;
    this->UserPos += v10;
    backtrackDataPos = v10;
  }
  if ( v6 <= 0 )
    return backtrackDataPos;
  v13 = Scaleform::GFx::ZLibFileImpl::InflateFromStream(this, v12, v6);
  if ( v13 < 4096 )
  {
    if ( v13 > 0 )
    {
      v15 = 4096 - this->BacktrackTail;
      if ( v15 >= v13 )
        v15 = v13;
      if ( v15 > 0 )
      {
        memcpy(&this->BacktrackBuffer[this->BacktrackTail], v12, v15);
        v12 += v15;
        this->BacktrackTail += v15;
      }
      if ( v13 > v15 )
      {
        this->BacktrackTail = v13 - v15;
        memcpy(this->BacktrackBuffer, v12, v13 - v15);
      }
      BacktrackSize = this->BacktrackSize;
      if ( BacktrackSize < 4096 )
      {
        v17 = v13 + BacktrackSize;
        this->BacktrackSize = v17;
        if ( v17 > 4096 )
          this->BacktrackSize = 4096;
      }
    }
    this->UserPos = this->LogicalStreamPos;
    return v13 + backtrackDataPos;
  }
  else
  {
    this->BacktrackTail = 4096;
    this->BacktrackSize = 4096;
    memcpy(this->BacktrackBuffer, &v12[v13 - 4096], sizeof(this->BacktrackBuffer));
    this->UserPos = this->LogicalStreamPos;
    return v13 + backtrackDataPos;
  }
}
