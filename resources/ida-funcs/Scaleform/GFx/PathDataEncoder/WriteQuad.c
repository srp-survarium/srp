unsigned int __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteQuad(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        int cx,
        int cy,
        int ax,
        int ay)
{
  int v5; // ebx
  int v7; // ecx
  bool v8; // cc
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // edx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v14; // edi
  unsigned int v15; // ebp
  unsigned __int8 **Pages; // edx
  unsigned int v17; // edi
  unsigned __int8 *v18; // edx
  int v19; // eax
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v20; // edi
  unsigned int v21; // ebp
  int v22; // ecx
  unsigned int v23; // ebx
  unsigned __int8 *v24; // edx
  char v25; // cl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v26; // esi
  unsigned int v27; // edi
  unsigned __int8 v28; // bl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v30; // edi
  unsigned int v31; // ebp
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v32; // edi
  unsigned int v33; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v34; // edi
  unsigned int v35; // ebp
  int v36; // ecx
  unsigned int Size; // ebx
  unsigned __int8 *v38; // edx
  char v39; // cl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v40; // esi
  unsigned int v41; // edi
  unsigned __int8 v42; // bl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v43; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v44; // ecx
  int v45; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v46; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v47; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v48; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v49; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v50; // ecx
  int v51; // ebx
  int v52; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v53; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v54; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v55; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v56; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v57; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v58; // ecx
  int v59; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v60; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v61; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v62; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v63; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v64; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v65; // ecx
  int v66; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v67; // ecx
  int v68; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v69; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v70; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v71; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v72; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v73; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v74; // ecx
  int v75; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v76; // ecx
  int v77; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v78; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v79; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v80; // ecx
  int v81; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v82; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v84; // ecx
  int v85; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v86; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v87; // ecx
  int v88; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v89; // ecx
  int v90; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v91; // ecx
  int v92; // [esp+10h] [ebp-8h]
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v93; // [esp+10h] [ebp-8h]

  v5 = cx;
  v7 = cy;
  v8 = cy <= cx;
  v9 = cx;
  v10 = cx;
  v92 = cx;
  if ( cy < cx )
  {
    v9 = cy;
    cx = cy;
  }
  if ( !v8 )
  {
    v10 = cy;
    v92 = cy;
  }
  v11 = ax;
  if ( ax < v9 )
    cx = ax;
  if ( ax > v10 )
    v92 = ax;
  v12 = ay;
  if ( ay >= cx )
    v12 = cx;
  v13 = ay;
  if ( ay <= v92 )
    v13 = v92;
  if ( v12 < -16 || v13 > 15 )
  {
    if ( v12 < -64 || v13 > 63 )
    {
      if ( v12 < -256 || v13 > 255 )
      {
        if ( v12 < -1024 || v13 > 1023 )
        {
          if ( v12 < -4096 || v13 > 4095 )
          {
            if ( v12 < -16384 || v13 > 0x3FFF )
            {
              if ( v12 < -65536 || v13 > 0xFFFF )
              {
                LOBYTE(cx) = (16 * v5) | 0xF;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&cx);
                Data = this->Data;
                LOBYTE(cx) = v5 >> 4;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  Data,
                  (unsigned __int8 *)&cx);
                v84 = this->Data;
                LOBYTE(cx) = ((_BYTE)cy << 7) | (v5 >> 12) & 0x7F;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v84,
                  (unsigned __int8 *)&cx);
                v85 = cy;
                LOBYTE(cy) = cy >> 1;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&cy);
                v86 = this->Data;
                LOBYTE(cy) = v85 >> 9;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v86,
                  (unsigned __int8 *)&cy);
                v87 = this->Data;
                cy = (v85 >> 17) & 0xFFFFFF03;
                v88 = ax;
                LOBYTE(cy) = (4 * ax) | cy;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v87,
                  (unsigned __int8 *)&cy);
                LOBYTE(cy) = v88 >> 6;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&cy);
                v89 = this->Data;
                LOBYTE(cy) = (32 * ay) | (v88 >> 14) & 0x1F;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v89,
                  (unsigned __int8 *)&cy);
                v90 = ay;
                v91 = this->Data;
                LOBYTE(ay) = ay >> 3;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v91,
                  (unsigned __int8 *)&ay);
                LOBYTE(ay) = v90 >> 11;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&ay);
                return 10;
              }
              else
              {
                v73 = this->Data;
                LOBYTE(cx) = (16 * v5) | 0xE;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v73,
                  (unsigned __int8 *)&cx);
                LOBYTE(cx) = v5 >> 4;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&cx);
                v74 = this->Data;
                LOBYTE(cx) = (32 * cy) | (v5 >> 12) & 0x1F;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v74,
                  (unsigned __int8 *)&cx);
                v75 = cy;
                v76 = this->Data;
                LOBYTE(cy) = cy >> 3;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v76,
                  (unsigned __int8 *)&cy);
                cy = (v75 >> 11) & 0xFFFFFF3F;
                v77 = ax;
                v78 = this->Data;
                LOBYTE(cy) = ((_BYTE)ax << 6) | cy;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v78,
                  (unsigned __int8 *)&cy);
                v79 = this->Data;
                LOBYTE(cy) = v77 >> 2;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v79,
                  (unsigned __int8 *)&cy);
                v80 = this->Data;
                LOBYTE(cy) = ((_BYTE)ay << 7) | (v77 >> 10) & 0x7F;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v80,
                  (unsigned __int8 *)&cy);
                v81 = ay;
                LOBYTE(ay) = ay >> 1;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  this->Data,
                  (unsigned __int8 *)&ay);
                v82 = this->Data;
                LOBYTE(ay) = v81 >> 9;
                Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                  v82,
                  (unsigned __int8 *)&ay);
                return 9;
              }
            }
            else
            {
              v64 = this->Data;
              LOBYTE(cx) = (16 * v5) | 0xD;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v64,
                (unsigned __int8 *)&cx);
              LOBYTE(cx) = v5 >> 4;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                this->Data,
                (unsigned __int8 *)&cx);
              v65 = this->Data;
              LOBYTE(cx) = (8 * cy) | (v5 >> 12) & 7;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v65,
                (unsigned __int8 *)&cx);
              v66 = cy;
              v67 = this->Data;
              LOBYTE(cy) = cy >> 5;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v67,
                (unsigned __int8 *)&cy);
              cy = (v66 >> 13) & 0xFFFFFF03;
              v68 = ax;
              v69 = this->Data;
              LOBYTE(cy) = (4 * ax) | cy;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v69,
                (unsigned __int8 *)&cy);
              v70 = this->Data;
              LOBYTE(cy) = v68 >> 6;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v70,
                (unsigned __int8 *)&cy);
              v71 = this->Data;
              LOBYTE(cy) = (2 * ay) | (v68 >> 14) & 1;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v71,
                (unsigned __int8 *)&cy);
              v72 = this->Data;
              LOBYTE(ay) = ay >> 7;
              Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
                v72,
                (unsigned __int8 *)&ay);
              return 8;
            }
          }
          else
          {
            v56 = this->Data;
            LOBYTE(cx) = (16 * v5) | 0xC;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v56,
              (unsigned __int8 *)&cx);
            v57 = this->Data;
            LOBYTE(cx) = v5 >> 4;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v57,
              (unsigned __int8 *)&cx);
            v58 = this->Data;
            LOBYTE(cx) = (2 * cy) | (v5 >> 12) & 1;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v58,
              (unsigned __int8 *)&cx);
            v59 = ax;
            v60 = this->Data;
            LOBYTE(cy) = ((_BYTE)ax << 6) | (cy >> 7) & 0x3F;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v60,
              (unsigned __int8 *)&cy);
            v61 = this->Data;
            LOBYTE(cy) = v59 >> 2;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v61,
              (unsigned __int8 *)&cy);
            v62 = this->Data;
            LOBYTE(cy) = (8 * ay) | (v59 >> 10) & 7;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v62,
              (unsigned __int8 *)&cy);
            v63 = this->Data;
            LOBYTE(ay) = ay >> 5;
            Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
              v63,
              (unsigned __int8 *)&ay);
            return 7;
          }
        }
        else
        {
          v49 = this->Data;
          LOBYTE(cx) = (16 * v5) | 0xB;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            v49,
            (unsigned __int8 *)&cx);
          v50 = this->Data;
          LOBYTE(cx) = ((_BYTE)cy << 7) | (v5 >> 4) & 0x7F;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            v50,
            (unsigned __int8 *)&cx);
          v51 = cy;
          LOBYTE(cy) = cy >> 1;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            this->Data,
            (unsigned __int8 *)&cy);
          cy = (v51 >> 9) & 0xFFFFFF03;
          v52 = ax;
          v53 = this->Data;
          LOBYTE(cy) = (4 * ax) | cy;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            v53,
            (unsigned __int8 *)&cy);
          v54 = this->Data;
          LOBYTE(cy) = (32 * ay) | (v52 >> 6) & 0x1F;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            v54,
            (unsigned __int8 *)&cy);
          v55 = this->Data;
          LOBYTE(ay) = ay >> 3;
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
            v55,
            (unsigned __int8 *)&ay);
          return 6;
        }
      }
      else
      {
        v43 = this->Data;
        LOBYTE(cx) = (16 * v5) | 0xA;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v43,
          (unsigned __int8 *)&cx);
        v44 = this->Data;
        LOBYTE(cx) = (32 * cy) | (v5 >> 4) & 0x1F;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v44,
          (unsigned __int8 *)&cx);
        v45 = ax;
        v46 = this->Data;
        LOBYTE(cy) = ((_BYTE)ax << 6) | (cy >> 3) & 0x3F;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v46,
          (unsigned __int8 *)&cy);
        v47 = this->Data;
        LOBYTE(cy) = ((_BYTE)ay << 7) | (v45 >> 2) & 0x7F;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v47,
          (unsigned __int8 *)&cy);
        v48 = this->Data;
        LOBYTE(ay) = ay >> 1;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v48,
          (unsigned __int8 *)&ay);
        return 5;
      }
    }
    else
    {
      v30 = this->Data;
      v31 = this->Data->Size >> 12;
      LOBYTE(cx) = (16 * v5) | 9;
      if ( v31 >= v30->NumPages )
      {
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v30,
          v31);
        v7 = cy;
        v11 = ax;
      }
      v30->Pages[v31][v30->Size++ & 0xFFF] = cx;
      v32 = this->Data;
      LOBYTE(cx) = (8 * v7) | (v5 >> 4) & 7;
      v33 = v32->Size >> 12;
      if ( v33 >= v32->NumPages )
      {
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v32,
          v32->Size >> 12);
        v7 = cy;
        v11 = ax;
      }
      v32->Pages[v33][v32->Size++ & 0xFFF] = cx;
      v34 = this->Data;
      v35 = this->Data->Size >> 12;
      LOBYTE(cy) = (4 * v11) | (v7 >> 5) & 3;
      if ( v35 < v34->NumPages )
      {
        v36 = (unsigned __int8)ay;
      }
      else
      {
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v34,
          v35);
        v11 = ax;
        LOBYTE(v36) = ay;
      }
      Size = v34->Size;
      v38 = v34->Pages[v35];
      ay = v36;
      v38[Size & 0xFFF] = cy;
      v39 = ay;
      ++v34->Size;
      v40 = this->Data;
      v41 = v40->Size >> 12;
      v42 = (2 * v39) | (v11 >> 6) & 1;
      if ( v41 >= v40->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v40,
          v40->Size >> 12);
      v40->Pages[v41][v40->Size++ & 0xFFF] = v42;
      return 4;
    }
  }
  else
  {
    v14 = this->Data;
    v15 = this->Data->Size >> 12;
    LOBYTE(cx) = (16 * v5) | 8;
    v93 = v14;
    if ( v15 >= v14->NumPages )
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v14,
        v15);
      LOBYTE(v7) = cy;
      v11 = ax;
    }
    Pages = v14->Pages;
    v17 = v14->Size;
    v18 = Pages[v15];
    cy = v11;
    v18[v17 & 0xFFF] = cx;
    ++v93->Size;
    v19 = cy;
    v20 = this->Data;
    v21 = this->Data->Size >> 12;
    LOBYTE(cy) = ((_BYTE)cy << 6) | (2 * v7) & 0x3F | (v5 >> 4) & 1;
    if ( v21 < v20->NumPages )
    {
      v22 = (unsigned __int8)ay;
    }
    else
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v20,
        v21);
      v19 = ax;
      LOBYTE(v22) = ay;
    }
    v23 = v20->Size;
    v24 = v20->Pages[v21];
    ay = v22;
    v24[v23 & 0xFFF] = cy;
    v25 = ay;
    ++v20->Size;
    v26 = this->Data;
    v27 = v26->Size >> 12;
    v28 = (8 * v25) | (v19 >> 2) & 7;
    if ( v27 >= v26->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v26,
        v26->Size >> 12);
    v26->Pages[v27][v26->Size++ & 0xFFF] = v28;
    return 3;
  }
}
