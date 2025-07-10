unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int cx,
        int cy,
        int ax,
        int ay)
{
  int v5; // ebx
  int v7; // eax
  int v8; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v14; // ecx
  int v15; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v16; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v17; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v18; // ecx
  int v19; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v20; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v21; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v22; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v23; // ecx
  int v24; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v25; // ecx
  int v26; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v27; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v28; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v29; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v30; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v31; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v32; // ecx
  int v33; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v34; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v35; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v36; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v37; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v38; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v39; // ecx
  int v40; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v41; // ecx
  int v42; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v43; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v44; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v45; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v46; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v48; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v49; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v50; // ecx
  int v51; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v52; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v53; // ecx
  int v54; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v55; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v56; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v57; // ecx
  int v58; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v59; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v60; // ecx

  v5 = cx;
  v7 = cx;
  v8 = cx;
  if ( cy < cx )
    v7 = cy;
  if ( cy > cx )
    v8 = cy;
  if ( ax < v7 )
    v7 = ax;
  if ( ax > v8 )
    v8 = ax;
  if ( ay < v7 )
    v7 = ay;
  if ( ay > v8 )
    v8 = ay;
  if ( v7 < -16 || v8 > 15 )
  {
    if ( v7 < -64 || v8 > 63 )
    {
      if ( v7 < -256 || v8 > 255 )
      {
        if ( v7 < -1024 || v8 > 1023 )
        {
          if ( v7 < -4096 || v8 > 4095 )
          {
            if ( v7 < -16384 || v8 > 0x3FFF )
            {
              Data = this->Data;
              LOBYTE(cx) = (16 * cx) | 0xE;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                Data,
                (const unsigned __int8 *)&cx);
              LOBYTE(cx) = v5 >> 4;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cx);
              v48 = this->Data;
              LOBYTE(cx) = v5 >> 12;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v48,
                (const unsigned __int8 *)&cx);
              v49 = this->Data;
              LOBYTE(cx) = v5 >> 20;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v49,
                (const unsigned __int8 *)&cx);
              v50 = this->Data;
              LOBYTE(cx) = (8 * cy) | (v5 >> 28) & 7;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v50,
                (const unsigned __int8 *)&cx);
              v51 = cy;
              v52 = this->Data;
              LOBYTE(cy) = cy >> 5;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v52,
                (const unsigned __int8 *)&cy);
              v53 = this->Data;
              LOBYTE(cy) = v51 >> 13;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v53,
                (const unsigned __int8 *)&cy);
              LOBYTE(cy) = v51 >> 21;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cy);
              cy = (v51 >> 29) & 0xFFFFFF03;
              v54 = ax;
              v55 = this->Data;
              LOBYTE(cy) = (4 * ax) | cy;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v55,
                (const unsigned __int8 *)&cy);
              LOBYTE(cy) = v54 >> 6;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cy);
              v56 = this->Data;
              LOBYTE(cy) = v54 >> 14;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v56,
                (const unsigned __int8 *)&cy);
              LOBYTE(cy) = v54 >> 22;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cy);
              v57 = this->Data;
              LOBYTE(cy) = (2 * ay) | (v54 >> 30) & 1;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v57,
                (const unsigned __int8 *)&cy);
              v58 = ay;
              v59 = this->Data;
              LOBYTE(cy) = ay >> 7;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v59,
                (const unsigned __int8 *)&cy);
              LOBYTE(cy) = v58 >> 15;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cy);
              v60 = this->Data;
              LOBYTE(cy) = v58 >> 23;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v60,
                (const unsigned __int8 *)&cy);
              return 16;
            }
            else
            {
              v38 = this->Data;
              LOBYTE(cx) = (16 * cx) | 0xD;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v38,
                (const unsigned __int8 *)&cx);
              LOBYTE(cx) = v5 >> 4;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                this->Data,
                (const unsigned __int8 *)&cx);
              v39 = this->Data;
              LOBYTE(cx) = (8 * cy) | (v5 >> 12) & 7;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v39,
                (const unsigned __int8 *)&cx);
              v40 = cy;
              v41 = this->Data;
              LOBYTE(cy) = cy >> 5;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v41,
                (const unsigned __int8 *)&cy);
              cy = (v40 >> 13) & 0xFFFFFF03;
              v42 = ax;
              v43 = this->Data;
              LOBYTE(cy) = (4 * ax) | cy;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v43,
                (const unsigned __int8 *)&cy);
              v44 = this->Data;
              LOBYTE(cy) = v42 >> 6;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v44,
                (const unsigned __int8 *)&cy);
              v45 = this->Data;
              LOBYTE(cy) = (2 * ay) | (v42 >> 14) & 1;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v45,
                (const unsigned __int8 *)&cy);
              v46 = this->Data;
              LOBYTE(cy) = ay >> 7;
              Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                v46,
                (const unsigned __int8 *)&cy);
              return 8;
            }
          }
          else
          {
            v30 = this->Data;
            LOBYTE(cx) = (16 * cx) | 0xC;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v30,
              (const unsigned __int8 *)&cx);
            v31 = this->Data;
            LOBYTE(cx) = v5 >> 4;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v31,
              (const unsigned __int8 *)&cx);
            v32 = this->Data;
            LOBYTE(cx) = (2 * cy) | (v5 >> 12) & 1;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v32,
              (const unsigned __int8 *)&cx);
            v33 = ax;
            v34 = this->Data;
            LOBYTE(cy) = ((_BYTE)ax << 6) | (cy >> 7) & 0x3F;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v34,
              (const unsigned __int8 *)&cy);
            v35 = this->Data;
            LOBYTE(cy) = v33 >> 2;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v35,
              (const unsigned __int8 *)&cy);
            v36 = this->Data;
            LOBYTE(cy) = (8 * ay) | (v33 >> 10) & 7;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v36,
              (const unsigned __int8 *)&cy);
            v37 = this->Data;
            LOBYTE(cy) = ay >> 5;
            Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v37,
              (const unsigned __int8 *)&cy);
            return 7;
          }
        }
        else
        {
          LOBYTE(cx) = (16 * cx) | 0xB;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            this->Data,
            (const unsigned __int8 *)&cx);
          v23 = this->Data;
          LOBYTE(cx) = ((_BYTE)cy << 7) | (v5 >> 4) & 0x7F;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            v23,
            (const unsigned __int8 *)&cx);
          v24 = cy;
          v25 = this->Data;
          LOBYTE(cy) = cy >> 1;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            v25,
            (const unsigned __int8 *)&cy);
          cy = (v24 >> 9) & 0xFFFFFF03;
          v26 = ax;
          v27 = this->Data;
          LOBYTE(cy) = (4 * ax) | cy;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            v27,
            (const unsigned __int8 *)&cy);
          v28 = this->Data;
          LOBYTE(cy) = (32 * ay) | (v26 >> 6) & 0x1F;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            v28,
            (const unsigned __int8 *)&cy);
          v29 = this->Data;
          LOBYTE(cy) = ay >> 3;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            v29,
            (const unsigned __int8 *)&cy);
          return 6;
        }
      }
      else
      {
        LOBYTE(cx) = (16 * cx) | 0xA;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (const unsigned __int8 *)&cx);
        v18 = this->Data;
        LOBYTE(cx) = (32 * cy) | (v5 >> 4) & 0x1F;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v18,
          (const unsigned __int8 *)&cx);
        v19 = ax;
        v20 = this->Data;
        LOBYTE(cy) = ((_BYTE)ax << 6) | (cy >> 3) & 0x3F;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v20,
          (const unsigned __int8 *)&cy);
        v21 = this->Data;
        LOBYTE(cy) = ((_BYTE)ay << 7) | (v19 >> 2) & 0x7F;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v21,
          (const unsigned __int8 *)&cy);
        v22 = this->Data;
        LOBYTE(cy) = ay >> 1;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v22,
          (const unsigned __int8 *)&cy);
        return 5;
      }
    }
    else
    {
      v13 = this->Data;
      LOBYTE(cx) = (16 * cx) | 9;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v13,
        (const unsigned __int8 *)&cx);
      v14 = this->Data;
      LOBYTE(cx) = (8 * cy) | (v5 >> 4) & 7;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v14,
        (const unsigned __int8 *)&cx);
      v15 = ax;
      v16 = this->Data;
      LOBYTE(cy) = (4 * ax) | (cy >> 5) & 3;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v16,
        (const unsigned __int8 *)&cy);
      v17 = this->Data;
      LOBYTE(cy) = (2 * ay) | (v15 >> 6) & 1;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v17,
        (const unsigned __int8 *)&cy);
      return 4;
    }
  }
  else
  {
    v9 = this->Data;
    LOBYTE(cx) = (16 * cx) | 8;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v9,
      (const unsigned __int8 *)&cx);
    v10 = this->Data;
    LOBYTE(cy) = ((_BYTE)ax << 6) | (2 * cy) & 0x3F | (v5 >> 4) & 1;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v10,
      (const unsigned __int8 *)&cy);
    v11 = this->Data;
    LOBYTE(cy) = (8 * ay) | (ax >> 2) & 7;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v11,
      (const unsigned __int8 *)&cy);
    return 3;
  }
}
