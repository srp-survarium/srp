void __thiscall Scaleform::MsgFormat::Evaluate(Scaleform::MsgFormat *this, unsigned int ind)
{
  char *v3; // eax
  char *v4; // eax
  _BYTE *v5; // ebx
  int (__thiscall *v6)(_BYTE *); // edx
  char v7; // al
  unsigned int v8; // esi
  int v9; // edi
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // esi
  void (__thiscall **v14)(_BYTE *, int); // esi
  int v15; // eax
  unsigned int v16; // edi
  int v17; // ebx
  char *v18; // eax
  void (__thiscall **v19)(_BYTE *, int); // esi
  int v20; // eax
  void (__thiscall **v21)(_BYTE *, int); // edi
  int v22; // eax
  char *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  Scaleform::MsgFormat::fmt_record *v26; // eax
  const char *Str; // esi
  void (__thiscall *v28)(const char *); // eax
  void (__thiscall **v29)(_BYTE *, int); // edi
  int v30; // eax
  char *v31; // eax
  unsigned int v32; // ecx
  void (__thiscall *v33)(_BYTE *, Scaleform::StringDataPtr *); // edx
  unsigned int Size; // eax
  unsigned int v35; // ebx
  int v36; // edi
  char *v37; // eax
  int v38; // eax
  Scaleform::MsgFormat::fmt_record *v39; // eax
  const char *v40; // esi
  void (__thiscall *v41)(const char *); // eax
  _BYTE *v42; // ebx
  void (__thiscall **v43)(_BYTE *, int); // edi
  int v44; // eax
  char *v45; // eax
  unsigned int v46; // ecx
  void (__thiscall *v47)(_BYTE *, Scaleform::StringDataPtr *); // edx
  int v48; // eax
  int v49; // eax
  char v50; // al
  unsigned int v51; // edi
  char v52; // bl
  char v53; // al
  unsigned int v54; // ecx
  int v55; // esi
  char *v56; // edx
  const char *v57; // esi
  unsigned int v58; // edx
  unsigned int v59; // esi
  unsigned int v60; // eax
  Scaleform::MsgFormat::fmt_record *v61; // ecx
  unsigned int v62; // eax
  Scaleform::MsgFormat::fmt_record *v63; // ecx
  char *v64; // eax
  unsigned int v65; // edi
  Scaleform::StringDataPtr v66; // [esp+0h] [ebp-48h] BYREF
  int v67; // [esp+8h] [ebp-40h]
  char v68; // [esp+1Ah] [ebp-2Eh]
  char v69; // [esp+1Bh] [ebp-2Dh]
  _BYTE *v70; // [esp+1Ch] [ebp-2Ch]
  unsigned int inda; // [esp+20h] [ebp-28h]
  int v72; // [esp+24h] [ebp-24h]
  unsigned int v73; // [esp+28h] [ebp-20h] BYREF
  unsigned int v74; // [esp+2Ch] [ebp-1Ch]
  Scaleform::StringDataPtr v75; // [esp+30h] [ebp-18h] BYREF
  Scaleform::StringDataPtr v76; // [esp+38h] [ebp-10h] BYREF
  _BYTE v77[8]; // [esp+40h] [ebp-8h] BYREF

  if ( ind >= 0x10 )
    v3 = (char *)&this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v3 = &this->Data.StaticArray[12 * ind];
  if ( *(_DWORD *)v3 != 2 )
    return;
  if ( ind >= 0x10 )
    v4 = (char *)&this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v4 = &this->Data.StaticArray[12 * ind];
  v5 = (_BYTE *)*((_DWORD *)v4 + 1);
  v6 = *(int (__thiscall **)(_BYTE *))(*(_DWORD *)v5 + 24);
  v70 = v5;
  v7 = v6(v5);
  v69 = v7;
  if ( !v7 )
  {
    if ( !v5[8] )
      (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v5 + 12))(v5);
    return;
  }
  if ( (v7 & 2) != 0 )
  {
    v8 = ind - 1;
    inda = ind - 1;
    v68 = 0;
    if ( ind )
    {
      v9 = 12 * v8;
      v72 = 12 * v8;
      while ( 1 )
      {
        if ( v68 )
          goto LABEL_30;
        if ( v8 >= 0x10 )
          v10 = (char *)&this->Data.DynamicArray.Data.Data[-16] + v9;
        else
          v10 = &this->Data.StaticArray[v9];
        v11 = *(_DWORD *)v10;
        if ( !v11 )
        {
          if ( v8 >= 0x10 )
            v23 = (char *)&this->Data.DynamicArray.Data.Data[-16] + v9;
          else
            v23 = &this->Data.StaticArray[v9];
          v24 = (unsigned __int8)v23[8];
          v73 = *((_DWORD *)v23 + 1);
          v74 = v24;
          if ( !Scaleform::IsSpace((Scaleform::StringDataPtr)__PAIR64__(v24, v73)) )
          {
            (*(void (__thiscall **)(_BYTE *, unsigned int *))(*(_DWORD *)v5 + 28))(v5, &v73);
            v68 = 1;
          }
          goto LABEL_27;
        }
        if ( v11 == 2 )
          break;
LABEL_27:
        --v8;
        v9 -= 12;
        inda = v8;
        v72 = v9;
        if ( v8 == -1 )
        {
          if ( v68 )
            goto LABEL_30;
          goto LABEL_29;
        }
      }
      if ( v8 >= 0x10 )
        v12 = (char *)&this->Data.DynamicArray.Data.Data[-16] + v9;
      else
        v12 = &this->Data.StaticArray[v9];
      v13 = *((_DWORD *)v12 + 1);
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(v13) & 4) != 0 )
      {
        v14 = (void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v5 + 28);
        Scaleform::StringDataPtr::StringDataPtr(&v75, "stub");
        (*v14)(v5, v15);
      }
      else if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(v13) & 8) != 0
             && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 44))(v13) == 2 )
      {
        v19 = (void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v5 + 28);
        Scaleform::StringDataPtr::StringDataPtr(&v76, "stub");
        (*v19)(v5, v20);
      }
      else
      {
        Scaleform::MsgFormat::Evaluate(this, inda);
        (*(void (__thiscall **)(int, Scaleform::StringDataPtr *))(*(_DWORD *)v13 + 16))(v13, &v66);
        if ( Scaleform::IsSpace(v66) )
          goto LABEL_26;
        v21 = (void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v5 + 28);
        v22 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 16))(v13, v77);
        (*v21)(v5, v22);
        v9 = v72;
      }
      v68 = 1;
LABEL_26:
      v8 = inda;
      goto LABEL_27;
    }
LABEL_29:
    v75.pStr = 0;
    v75.Size = 0;
    (*(void (__thiscall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_DWORD *)v5 + 28))(v5, &v75);
  }
LABEL_30:
  if ( (v69 & 1) != 0 )
  {
    inda = ind - 1;
    v68 = 0;
    if ( ind )
    {
      v16 = ind - 1;
      v17 = ind - 1;
      while ( 1 )
      {
        if ( v68 )
          goto LABEL_63;
        if ( v16 >= 0x10 )
          v18 = (char *)&this->Data.DynamicArray.Data.Data[v17 - 16];
        else
          v18 = &this->Data.StaticArray[v17 * 12];
        v25 = *(_DWORD *)v18;
        if ( v25 )
        {
          if ( v25 != 2 )
            goto LABEL_60;
          v26 = v16 >= 0x10
              ? &this->Data.DynamicArray.Data.Data[v17 - 16]
              : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[v17 * 12];
          Str = v26->RecValue.String.Str;
          (*(void (__thiscall **)(const char *, int))(*(_DWORD *)Str + 24))(Str, v67);
          Scaleform::MsgFormat::Evaluate(this, v16);
          v28 = *(void (__thiscall **)(const char *))(*(_DWORD *)Str + 16);
          v66.pStr = (const char *)&v66.Size;
          v28(Str);
          if ( Scaleform::IsSpace(v66) )
            goto LABEL_60;
          v29 = (void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v70 + 28);
          v30 = (*(int (__thiscall **)(const char *, _BYTE *))(*(_DWORD *)Str + 16))(Str, v77);
          (*v29)(v70, v30);
          v16 = inda;
        }
        else
        {
          if ( v16 >= 0x10 )
            v31 = (char *)&this->Data.DynamicArray.Data.Data[v17 - 16];
          else
            v31 = &this->Data.StaticArray[v17 * 12];
          v32 = (unsigned __int8)v31[8];
          v73 = *((_DWORD *)v31 + 1);
          v74 = v32;
          if ( Scaleform::IsSpace((Scaleform::StringDataPtr)__PAIR64__(v32, v73)) )
            goto LABEL_60;
          (*(void (__thiscall **)(_BYTE *, unsigned int *))(*(_DWORD *)v70 + 28))(v70, &v73);
        }
        v68 = 1;
LABEL_60:
        --v16;
        --v17;
        inda = v16;
        if ( v16 == -1 )
        {
          if ( v68 )
            goto LABEL_63;
          break;
        }
      }
    }
    v33 = *(void (__thiscall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_DWORD *)v70 + 28);
    v75.pStr = 0;
    v75.Size = 0;
    v33(v70, &v75);
  }
LABEL_63:
  if ( (v69 & 4) != 0 )
  {
    Size = this->Data.Size;
    v35 = ind + 1;
    v72 = ind + 1;
    v68 = 0;
    v73 = Size;
    if ( ind + 1 < Size )
    {
      v36 = 12 * v35;
      inda = 12 * v35;
      while ( 1 )
      {
        if ( v68 )
          goto LABEL_86;
        if ( v35 >= 0x10 )
          v37 = (char *)&this->Data.DynamicArray.Data.Data[-16] + v36;
        else
          v37 = &this->Data.StaticArray[v36];
        v38 = *(_DWORD *)v37;
        if ( v38 )
        {
          if ( v38 != 2 )
            goto LABEL_83;
          v39 = v35 >= 0x10
              ? (Scaleform::MsgFormat::fmt_record *)((char *)&this->Data.DynamicArray.Data.Data[-16] + v36)
              : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[v36];
          v40 = v39->RecValue.String.Str;
          (*(void (__thiscall **)(const char *, int))(*(_DWORD *)v40 + 24))(v40, v67);
          Scaleform::MsgFormat::Evaluate(this, v35);
          v41 = *(void (__thiscall **)(const char *))(*(_DWORD *)v40 + 16);
          v66.pStr = (const char *)&v66.Size;
          v41(v40);
          if ( Scaleform::IsSpace(v66) )
            goto LABEL_83;
          v42 = v70;
          v43 = (void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v70 + 36);
          v44 = (*(int (__thiscall **)(const char *, _BYTE *))(*(_DWORD *)v40 + 16))(v40, v77);
          (*v43)(v42, v44);
          v36 = inda;
          v35 = v72;
        }
        else
        {
          if ( v35 >= 0x10 )
            v45 = (char *)&this->Data.DynamicArray.Data.Data[-16] + v36;
          else
            v45 = &this->Data.StaticArray[v36];
          v46 = (unsigned __int8)v45[8];
          v75.pStr = (const char *)*((_DWORD *)v45 + 1);
          v75.Size = v46;
          if ( Scaleform::IsSpace((Scaleform::StringDataPtr)__PAIR64__(v46, (unsigned int)v75.pStr)) )
            goto LABEL_83;
          (*(void (__thiscall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_DWORD *)v70 + 36))(v70, &v75);
        }
        v68 = 1;
LABEL_83:
        ++v35;
        v36 += 12;
        v72 = v35;
        inda = v36;
        if ( v35 >= v73 )
        {
          if ( v68 )
            goto LABEL_86;
          break;
        }
      }
    }
    v47 = *(void (__thiscall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_DWORD *)v70 + 36);
    v75.pStr = 0;
    v75.Size = 0;
    v47(v70, &v75);
  }
LABEL_86:
  if ( (v69 & 8) != 0 )
  {
    v48 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v70 + 44))(v70) - 1;
    if ( v48 )
    {
      v49 = v48 - 1;
      if ( v49 )
      {
        if ( v49 == 1 )
        {
          v50 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v70 + 48))(v70);
          v51 = this->Data.Size;
          v52 = v50;
          v53 = 0;
          v54 = 0;
          if ( v51 )
          {
            v55 = 0;
            while ( 1 )
            {
              if ( v54 >= 0x10 )
                v56 = (char *)&this->Data.DynamicArray.Data.Data[v55 - 16];
              else
                v56 = &this->Data.StaticArray[v55 * 12];
              if ( *(_DWORD *)v56 == 2 )
              {
                if ( v53 == v52 )
                {
                  if ( v54 >= 0x10 )
                    v57 = this->Data.DynamicArray.Data.Data[v54 - 16].RecValue.String.Str;
                  else
                    v57 = *(const char **)&this->Data.StaticArray[12 * v54 + 4];
                  Scaleform::MsgFormat::Evaluate(this, v54);
                  v66.Size = (unsigned int)v57;
                  goto LABEL_124;
                }
                ++v53;
              }
              ++v54;
              ++v55;
              if ( v54 >= v51 )
                goto LABEL_125;
            }
          }
        }
        goto LABEL_125;
      }
      v58 = this->Data.Size;
      v59 = ind + 1;
      if ( ind + 1 < v58 )
      {
        v60 = v59;
        while ( 1 )
        {
          v61 = v59 >= 0x10
              ? &this->Data.DynamicArray.Data.Data[v60 - 16]
              : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[v60 * 12];
          if ( v61->RecType == eFmtType )
            break;
          ++v59;
          ++v60;
          if ( v59 >= v58 )
            goto LABEL_125;
        }
LABEL_120:
        if ( v59 >= 0x10 )
          v64 = (char *)&this->Data.DynamicArray.Data.Data[v59 - 16];
        else
          v64 = &this->Data.StaticArray[12 * v59];
        v65 = *((_DWORD *)v64 + 1);
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v65 + 24))(v65);
        Scaleform::MsgFormat::Evaluate(this, v59);
        v66.Size = v65;
LABEL_124:
        (*(void (__thiscall **)(_BYTE *, unsigned int))(*(_DWORD *)v70 + 52))(v70, v66.Size);
      }
    }
    else
    {
      v59 = ind - 1;
      if ( ind )
      {
        v62 = v59;
        do
        {
          v63 = v59 >= 0x10
              ? &this->Data.DynamicArray.Data.Data[v62 - 16]
              : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[v62 * 12];
          if ( v63->RecType == eFmtType )
            goto LABEL_120;
          --v59;
          --v62;
        }
        while ( v59 != -1 );
      }
    }
  }
LABEL_125:
  if ( !v70[8] )
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v70 + 12))(v70);
}
