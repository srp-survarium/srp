DName *__cdecl UnDecorator::composeDeclaration(DName *result, DName *symbol)
{
  int TypeEncoding; // eax
  int v3; // ebx
  bool v4; // zf
  DName *v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  const DName *BasedType; // eax
  const DName *v11; // eax
  int v12; // eax
  DName *v13; // eax
  const DName *v14; // eax
  DName *v15; // eax
  DName *v16; // eax
  DName *v17; // eax
  DName *v18; // eax
  DName *ExternalDataType; // eax
  int v20; // eax
  DName *Displacement; // eax
  DNameNode *v22; // ecx
  DName *v23; // eax
  DNameNode *v24; // ecx
  DName *v25; // eax
  DNameNode *v26; // ecx
  DName *v27; // eax
  DNameNode *v28; // ecx
  int v29; // eax
  DName *v30; // eax
  DNameNode *node; // ecx
  int v32; // eax
  const DName *v33; // eax
  DName *CallingConvention; // eax
  const DName *v35; // eax
  const DName *v36; // eax
  int v37; // eax
  DName *v38; // edi
  const DName *v39; // eax
  DName *v40; // eax
  char *Memory; // eax
  DName *v42; // eax
  DNameNode *v43; // ecx
  int v44; // eax
  int v45; // esi
  int v46; // eax
  DName *v47; // eax
  DName *v48; // eax
  DName *v49; // eax
  DName *v50; // eax
  DName *v51; // eax
  const DName *v52; // eax
  DName *v53; // eax
  const DName *ArgumentTypes; // eax
  DName *v55; // eax
  const DName *v56; // eax
  const DName *v57; // eax
  const DName *ThrowTypes; // eax
  DName *v59; // eax
  DName *v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  DName *v73; // eax
  int v74; // eax
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  DName *v79; // eax
  int v80; // eax
  BOOL v81; // eax
  DName *v82; // eax
  int v83; // eax
  BOOL v84; // eax
  int v85; // eax
  int v87; // eax
  int v88; // eax
  DName *v89; // eax
  DName *v90; // eax
  const DName *v91; // [esp-Ch] [ebp-84h]
  DName *v92; // [esp-8h] [ebp-80h]
  const DName *GuardNumber; // [esp-4h] [ebp-7Ch]
  DName v94; // [esp+Ch] [ebp-6Ch] BYREF
  DName v95; // [esp+14h] [ebp-64h] BYREF
  DName v96; // [esp+1Ch] [ebp-5Ch] BYREF
  DName v97; // [esp+24h] [ebp-54h] BYREF
  DName adjustment; // [esp+2Ch] [ebp-4Ch] BYREF
  DName vbptrDisp; // [esp+34h] [ebp-44h] BYREF
  DName vbindex; // [esp+3Ch] [ebp-3Ch] BYREF
  DName returnType; // [esp+44h] [ebp-34h] BYREF
  DName thisType; // [esp+4Ch] [ebp-2Ch] BYREF
  DName declaration; // [esp+54h] [ebp-24h] BYREF
  DName v104; // [esp+5Ch] [ebp-1Ch] BYREF
  DName vtorDisp; // [esp+64h] [ebp-14h] BYREF
  DName v106; // [esp+6Ch] [ebp-Ch] BYREF
  int v107; // [esp+74h] [ebp-4h]

  *((_DWORD *)&declaration + 1) &= 0xFFFF0000;
  declaration.node = 0;
  TypeEncoding = UnDecorator::getTypeEncoding();
  v3 = TypeEncoding;
  if ( !symbol->node || (v4 = (*((_DWORD *)symbol + 1) & 0x200) == 0, *((_DWORD *)&v104 + 1) = 1, v4) )
    *((_DWORD *)&v104 + 1) = 0;
  if ( TypeEncoding == 0xFFFF )
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  if ( TypeEncoding == 65534 )
  {
    operator+(result, DN_truncated, symbol);
    return result;
  }
  if ( TypeEncoding != 65533 )
  {
    v107 = TypeEncoding & 0x8000;
    if ( (TypeEncoding & 0x8000) != 0 )
    {
      *((_DWORD *)&vtorDisp + 1) = TypeEncoding & 0x1800;
      *((_DWORD *)&v106 + 1) = *((_DWORD *)&vtorDisp + 1) == 2048;
      v7 = *((_DWORD *)&vtorDisp + 1) == 2048 ? TypeEncoding & 0x400 : TypeEncoding & 0x1000;
      if ( !v7 || (v3 & 0x1B00) != 0x1000 )
      {
        v8 = *((_DWORD *)&v106 + 1) ? v3 & 0x400 : v3 & 0x1000;
        if ( !v8 || (v9 = v3 & 0x1B00, v9 != 4352) && v9 != 4608 )
        {
          if ( (v3 & 0x4000) != 0 )
          {
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 3) & 1) != 0 )
            {
              BasedType = UnDecorator::getBasedType(&adjustment);
              declaration = *operator+(&vbptrDisp, 32, BasedType);
            }
            else
            {
              v11 = UnDecorator::getBasedType(&adjustment);
              DName::operator|=(&declaration, v11);
            }
          }
          if ( *((_DWORD *)&v106 + 1) )
            v12 = v3 & 0x400;
          else
            v12 = v3 & 0x1000;
          if ( v12 && *((_DWORD *)&vtorDisp + 1) == 6144 )
          {
            GuardNumber = UnDecorator::getGuardNumber(&adjustment);
            v13 = DName::operator+(symbol, &vbindex, 123);
            v14 = DName::operator+(v13, &vbptrDisp, GuardNumber);
            DName::operator+=(&declaration, v14);
            UnDecorator::getVCallThunkType(&adjustment);
            if ( (UnDecorator::disableFlags & 0x1000) == 0 )
            {
              v15 = operator+(&vbindex, 44, &adjustment);
              v16 = DName::operator+(v15, &vbptrDisp, "}' ");
              DName::operator+=(&declaration, v16);
            }
            DName::operator+=(&declaration, "}'");
            UnDecorator::getCallingConvention(&adjustment);
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0
              && (~(UnDecorator::disableFlags >> 4) & 1) != 0
              && (UnDecorator::disableFlags & 0x1000) == 0 )
            {
              v17 = operator+(&returnType, 32, &adjustment);
              v18 = DName::operator+(v17, &vbindex, 32);
              ExternalDataType = DName::operator+(v18, &vbptrDisp, &declaration);
LABEL_39:
              declaration.node = ExternalDataType->node;
              v6 = *((_DWORD *)ExternalDataType + 1);
              *((_DWORD *)&declaration + 1) = v6;
              goto LABEL_140;
            }
            goto LABEL_139;
          }
          *((_DWORD *)&vbptrDisp + 1) &= 0xFFFF0000;
          *((_DWORD *)&vbindex + 1) &= 0xFFFF0000;
          *((_DWORD *)&vtorDisp + 1) &= 0xFFFF0000;
          *((_DWORD *)&adjustment + 1) &= 0xFFFF0000;
          *((_DWORD *)&thisType + 1) &= 0xFFFF0000;
          vbptrDisp.node = 0;
          vbindex.node = 0;
          vtorDisp.node = 0;
          adjustment.node = 0;
          thisType.node = 0;
          if ( *((_DWORD *)&v106 + 1) )
            v20 = v3 & 0x400;
          else
            v20 = v3 & 0x1000;
          if ( !v20 )
          {
LABEL_51:
            if ( *((_DWORD *)&v106 + 1) && (v3 & 0x700) != 0x200 )
            {
              if ( (UnDecorator::disableFlags & 0x60) == 0x60 )
              {
                v33 = UnDecorator::getThisType(&returnType);
                DName::operator|=(&thisType, v33);
              }
              else
              {
                v30 = UnDecorator::getThisType(&returnType);
                node = v30->node;
                v32 = *((_DWORD *)v30 + 1);
                thisType.node = node;
                *((_DWORD *)&thisType + 1) = v32;
              }
            }
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 4) & 1) != 0 )
            {
              CallingConvention = UnDecorator::getCallingConvention(&v97);
              declaration = *DName::operator+(CallingConvention, &returnType, &declaration);
            }
            else
            {
              v35 = UnDecorator::getCallingConvention(&v97);
              DName::operator|=(&declaration, v35);
            }
            if ( symbol->node )
            {
              if ( !declaration.node || (UnDecorator::disableFlags & 0x1000) != 0 )
              {
                v37 = *((_DWORD *)symbol + 1);
                declaration.node = symbol->node;
                *((_DWORD *)&declaration + 1) = v37;
              }
              else
              {
                v36 = operator+(&v97, 32, symbol);
                DName::operator+=(&declaration, v36);
              }
            }
            *((_DWORD *)&returnType + 1) &= 0xFFFF0000;
            v38 = 0;
            returnType.node = 0;
            if ( *((_DWORD *)&v104 + 1) )
            {
              v39 = UnDecorator::getReturnType(&v97, 0);
              v40 = operator+(&v104, (char *)&stru_95AF78, v39);
              DName::operator+=(&declaration, v40);
              if ( (UnDecorator::disableFlags & 0x1000) != 0 )
              {
LABEL_67:
                v5 = result;
                result->node = declaration.node;
                v6 = *((_DWORD *)&declaration + 1);
                goto LABEL_219;
              }
            }
            else
            {
              v38 = 0;
              Memory = HeapManager::getMemory(&heap, 8u, 0);
              if ( Memory )
              {
                *(_DWORD *)Memory = 0;
                Memory[4] = 0;
                *((_DWORD *)Memory + 1) &= 0xFFFF00FF;
                v38 = (DName *)Memory;
              }
              v42 = UnDecorator::getReturnType(&v97, v38);
              v43 = v42->node;
              v44 = *((_DWORD *)v42 + 1);
              returnType.node = v43;
              *((_DWORD *)&returnType + 1) = v44;
            }
            v45 = *((_DWORD *)&v106 + 1);
            if ( *((_DWORD *)&v106 + 1) )
              v46 = v3 & 0x400;
            else
              v46 = v3 & 0x1000;
            if ( !v46 )
            {
LABEL_83:
              ArgumentTypes = UnDecorator::getArgumentTypes(&v95);
              v55 = operator+(&v96, 40, ArgumentTypes);
              v56 = DName::operator+(v55, &v94, 41);
              DName::operator+=(&declaration, v56);
              if ( v45 && (v3 & 0x700) != 0x200 )
                DName::operator+=(&declaration, &thisType);
              if ( (UnDecorator::disableFlags & 0x100) != 0 )
              {
                ThrowTypes = UnDecorator::getThrowTypes(&v94);
                DName::operator|=(&declaration, ThrowTypes);
              }
              else
              {
                v57 = UnDecorator::getThrowTypes(&v94);
                DName::operator+=(&declaration, v57);
              }
              if ( (~(UnDecorator::disableFlags >> 2) & 1) != 0 && v38 )
              {
                v6 = *((_DWORD *)&returnType + 1);
                *v38 = declaration;
                declaration.node = returnType.node;
                *((_DWORD *)&declaration + 1) = v6;
                goto LABEL_140;
              }
LABEL_139:
              v6 = *((_DWORD *)&declaration + 1);
LABEL_140:
              if ( v107 )
                v70 = (v3 & 0x1800) - 2048;
              else
                v70 = v3 & 0x6000;
              if ( v70 )
                goto LABEL_207;
              if ( (~(UnDecorator::disableFlags >> 9) & 1) != 0 )
              {
                if ( v107 )
                  v71 = (v3 & 0x1800) - 2048;
                else
                  v71 = v3 & 0x6000;
                if ( !v71 && (!v107 || (v3 & 0x700) == 512) )
                {
                  v73 = operator+(&v94, "static ", &declaration);
                  declaration.node = v73->node;
                  v6 = *((_DWORD *)v73 + 1);
                  *((_DWORD *)&declaration + 1) = v6;
                }
                if ( v107 )
                {
                  if ( (v3 & 0x700) == 0x100 )
                  {
LABEL_177:
                    v79 = operator+(&v94, "virtual ", &declaration);
                    declaration.node = v79->node;
                    v6 = *((_DWORD *)v79 + 1);
                    *((_DWORD *)&declaration + 1) = v6;
                    goto LABEL_178;
                  }
                  v74 = (v3 & 0x1800) - 2048;
                }
                else
                {
                  v74 = v3 & 0x6000;
                }
                if ( v74 )
                  v75 = v3 & 0x1000;
                else
                  v75 = v3 & 0x400;
                if ( v75 )
                {
                  v76 = v107 ? (v3 & 0x1800) - 2048 : v3 & 0x6000;
                  if ( !v76 && (v3 & 0x700) == 0x500 )
                    goto LABEL_177;
                  v77 = v107 ? (v3 & 0x1800) - 2048 : v3 & 0x6000;
                  if ( !v77 && (v3 & 0x700) == 0x600 )
                    goto LABEL_177;
                  v78 = v107 ? (v3 & 0x1800) - 2048 : v3 & 0x6000;
                  if ( !v78 && (v3 & 0x700) == 0x400 )
                    goto LABEL_177;
                }
              }
LABEL_178:
              if ( (~(UnDecorator::disableFlags >> 7) & 1) != 0 )
              {
                if ( v107 )
                  v80 = (v3 & 0x1800) - 2048;
                else
                  v80 = v3 & 0x6000;
                if ( v80 || (!v107 ? (v81 = (v3 & 0x1800) == 2048) : (v81 = (v3 & 0xC0) == 64), !v81) )
                {
                  if ( v107 )
                    v83 = (v3 & 0x1800) - 2048;
                  else
                    v83 = v3 & 0x6000;
                  if ( v83 || (!v107 ? (v84 = (v3 & 0x1800) == 4096) : (v84 = (v3 & 0xC0) == 0x80), !v84) )
                  {
                    if ( v107 )
                      v85 = (v3 & 0x1800) - 2048;
                    else
                      v85 = v3 & 0x6000;
                    if ( v85 )
                      goto LABEL_207;
                    if ( !(v107 ? (v3 & 0xC0) == 0 : (v3 & 0x1800) == 0) )
                      goto LABEL_207;
                    v82 = operator+(&v94, "public: ", &declaration);
                  }
                  else
                  {
                    v82 = operator+(&v94, "protected: ", &declaration);
                  }
                }
                else
                {
                  v82 = operator+(&v94, "private: ", &declaration);
                }
                declaration.node = v82->node;
                v6 = *((_DWORD *)v82 + 1);
                *((_DWORD *)&declaration + 1) = v6;
              }
LABEL_207:
              if ( v107 )
                v87 = (v3 & 0x1800) - 2048;
              else
                v87 = v3 & 0x6000;
              if ( v87 )
                v88 = v3 & 0x1000;
              else
                v88 = v3 & 0x400;
              if ( v88 && (UnDecorator::disableFlags & 0x1000) == 0 )
              {
                v89 = operator+(&v94, "[thunk]:", &declaration);
                declaration.node = v89->node;
                v6 = *((_DWORD *)v89 + 1);
                *((_DWORD *)&declaration + 1) = v6;
              }
              if ( ((unsigned int)&_sbh_sizeHeaderList & v3) != 0 )
              {
                v90 = operator+(&v94, "extern \"C\" ", &declaration);
                declaration.node = v90->node;
                v6 = *((_DWORD *)v90 + 1);
              }
              v5 = result;
              result->node = declaration.node;
              goto LABEL_219;
            }
            if ( *((_DWORD *)&v106 + 1) )
            {
              if ( (v3 & 0x700) == 0x600 )
              {
                v92 = &v97;
                v47 = operator+(&v94, "`vtordispex{", &vbptrDisp);
                v48 = DName::operator+(v47, &v95, 44);
                v49 = DName::operator+(v48, &v96, &vbindex);
                v50 = DName::operator+(v49, &v106, 44);
                v51 = DName::operator+(v50, &v104, &vtorDisp);
LABEL_80:
                v52 = DName::operator+(v51, v92, 44);
                DName::operator+=(&declaration, v52);
LABEL_82:
                v53 = DName::operator+(&adjustment, &v94, "}' ");
                DName::operator+=(&declaration, v53);
                goto LABEL_83;
              }
              if ( (v3 & 0x700) == 0x500 )
              {
                v92 = &v94;
                v51 = operator+(&v95, "`vtordisp{", &vtorDisp);
                goto LABEL_80;
              }
            }
            DName::operator+=(&declaration, "`adjustor{");
            goto LABEL_82;
          }
          if ( *((_DWORD *)&v106 + 1) )
          {
            if ( (v3 & 0x700) == 0x600 )
            {
              Displacement = UnDecorator::getDisplacement(&returnType);
              v22 = Displacement->node;
              *((_DWORD *)&vbptrDisp + 1) = *((_DWORD *)Displacement + 1);
              vbptrDisp.node = v22;
              v23 = UnDecorator::getDisplacement(&returnType);
              v24 = v23->node;
              *((_DWORD *)&vbindex + 1) = *((_DWORD *)v23 + 1);
              vbindex.node = v24;
              v25 = UnDecorator::getDisplacement(&returnType);
LABEL_49:
              v26 = v25->node;
              *((_DWORD *)&vtorDisp + 1) = *((_DWORD *)v25 + 1);
              vtorDisp.node = v26;
              goto LABEL_50;
            }
            if ( (v3 & 0x700) == 0x500 )
            {
              v25 = UnDecorator::getDisplacement(&returnType);
              goto LABEL_49;
            }
          }
LABEL_50:
          v27 = UnDecorator::getDisplacement(&returnType);
          v28 = v27->node;
          v29 = *((_DWORD *)v27 + 1);
          adjustment.node = v28;
          *((_DWORD *)&adjustment + 1) = v29;
          goto LABEL_51;
        }
      }
    }
    DName::operator+=(&declaration, symbol);
    if ( v107 )
    {
      v61 = (v3 & 0x1800) - 2048;
    }
    else
    {
      switch ( v3 & 0x7C00 )
      {
        case 26624:
        case 28672:
          UnDecorator::getVfTableType(result, &declaration);
          return result;
        case 24576:
          v91 = UnDecorator::getGuardNumber(&v94);
          v59 = DName::operator+(&declaration, &v96, 123);
          v60 = DName::operator+(v59, &v95, v91);
          DName::operator+(v60, result, "}'");
          return result;
        case 31744:
          UnDecorator::getVdispMapType(result, &declaration);
          return result;
      }
      v61 = v3 & 0x6000;
    }
    if ( v61 )
      v62 = v3 & 0x1000;
    else
      v62 = v3 & 0x400;
    if ( v62 && v107 != 0 && (v3 & 0x1B00) == 4096 )
    {
      DName::operator+=(&declaration, "`local static destructor helper'");
    }
    else
    {
      if ( v107 )
        v63 = (v3 & 0x1800) - 2048;
      else
        v63 = v3 & 0x6000;
      if ( v63 )
        v64 = v3 & 0x1000;
      else
        v64 = v3 & 0x400;
      if ( v64 && v107 != 0 && (v3 & 0x1B00) == 4352 )
      {
        DName::operator+=(&declaration, "`template static data member constructor helper'");
      }
      else
      {
        if ( v107 )
          v65 = (v3 & 0x1800) - 2048;
        else
          v65 = v3 & 0x6000;
        if ( v65 )
          v66 = v3 & 0x1000;
        else
          v66 = v3 & 0x400;
        if ( v66 && v107 != 0 && (v3 & 0x1B00) == 4608 )
        {
          DName::operator+=(&declaration, "`template static data member destructor helper'");
        }
        else
        {
          if ( v107 )
            goto LABEL_129;
          if ( (v3 & 0x7C00) == 0x7800 )
            goto LABEL_67;
        }
      }
    }
    if ( !v107 )
    {
      v67 = v3 & 0x6000;
      goto LABEL_131;
    }
LABEL_129:
    v67 = (v3 & 0x1800) - 2048;
LABEL_131:
    if ( v67 )
      v68 = v3 & 0x1000;
    else
      v68 = v3 & 0x400;
    if ( v68 && ((v69 = v3 & 0x1B00, v107 != 0 && v69 == 4352) || v107 != 0 && v69 == 4608) )
      ExternalDataType = operator+(&v94, (char *)&stru_95AF78, &declaration);
    else
      ExternalDataType = UnDecorator::getExternalDataType(&v94, &declaration);
    goto LABEL_39;
  }
  v5 = result;
  result->node = symbol->node;
  v6 = *((_DWORD *)symbol + 1);
LABEL_219:
  *((_DWORD *)v5 + 1) = v6;
  return v5;
}
