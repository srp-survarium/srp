DName *__cdecl UnDecorator::getFunctionIndirectType(DName *result, const DName *superType)
{
  char v2; // cl
  DName *v3; // eax
  int v4; // ebx
  const char *v5; // eax
  bool v6; // cc
  DName *v7; // eax
  DNameNode *node; // ecx
  bool v9; // zf
  const DName *Scope; // eax
  DName *v11; // eax
  DName *v12; // eax
  DNameNode *v13; // ecx
  char v14; // al
  DName *v15; // eax
  DNameNode *v16; // ecx
  int v17; // eax
  const DName *BasedType; // eax
  DName *v19; // eax
  DName *v20; // eax
  DNameNode *v21; // ecx
  int v22; // eax
  const DName *v23; // eax
  const DName *v24; // eax
  DName *CallingConvention; // eax
  DName *v26; // eax
  DNameNode *v27; // ecx
  int v28; // eax
  const DName *v29; // eax
  DName *v30; // eax
  DName *v31; // eax
  DNameNode *v32; // ecx
  int v33; // eax
  char *Memory; // eax
  DName *v35; // esi
  const DName *ArgumentTypes; // eax
  DName *v37; // eax
  const DName *v38; // eax
  const DName *v39; // eax
  const DName *ThrowTypes; // eax
  DName v41; // [esp+0h] [ebp-30h] BYREF
  DName v42; // [esp+8h] [ebp-28h] BYREF
  DName v43; // [esp+10h] [ebp-20h] BYREF
  DName returnType; // [esp+18h] [ebp-18h] BYREF
  DName thisType; // [esp+20h] [ebp-10h] BYREF
  DName fitType; // [esp+28h] [ebp-8h] BYREF

  v2 = *UnDecorator::gName;
  if ( !*UnDecorator::gName )
  {
    operator+(result, DN_truncated, superType);
    return result;
  }
  if ( (v2 < 54 || v2 > 57) && v2 != 95 )
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  v4 = v2 - 54;
  v5 = ++UnDecorator::gName;
  if ( v2 == 95 )
  {
    if ( !*v5 )
    {
      operator+(result, DN_truncated, superType);
      return result;
    }
    v4 = *v5 - 61;
    UnDecorator::gName = v5 + 1;
    if ( v4 >= 4 )
    {
      v6 = v4 <= 7;
      goto LABEL_15;
    }
  }
  else if ( v4 >= 0 )
  {
    v6 = v4 <= 3;
LABEL_15:
    if ( v6 )
      goto LABEL_17;
  }
  v4 = -1;
LABEL_17:
  if ( v4 == -1 )
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  thisType.node = 0;
  *((_DWORD *)&thisType + 1) &= 0xFFFF0000;
  fitType = *superType;
  if ( (v4 & 2) != 0 )
  {
    v7 = operator+(&v43, "::", &fitType);
    node = v7->node;
    *((_DWORD *)&fitType + 1) = *((_DWORD *)v7 + 1);
    v9 = *UnDecorator::gName == 0;
    fitType.node = node;
    if ( v9 )
    {
      v12 = operator+(&v41, DN_truncated, &fitType);
    }
    else
    {
      Scope = UnDecorator::getScope(&v42);
      v11 = operator+(&v41, 32, Scope);
      v12 = DName::operator+(v11, &v43, &fitType);
    }
    v13 = v12->node;
    *((_DWORD *)&fitType + 1) = *((_DWORD *)v12 + 1);
    v14 = *UnDecorator::gName;
    fitType.node = v13;
    if ( !v14 )
    {
      operator+(result, DN_truncated, &fitType);
      return result;
    }
    if ( v14 != 64 )
    {
      DName::DName(result, DN_invalid);
      return result;
    }
    ++UnDecorator::gName;
    if ( (UnDecorator::disableFlags & 0x60) == 0x60 )
    {
      v23 = UnDecorator::getThisType(&v41);
      DName::operator|=(&thisType, v23);
    }
    else
    {
      v15 = UnDecorator::getThisType(&v41);
      v16 = v15->node;
      v17 = *((_DWORD *)v15 + 1);
      thisType.node = v16;
      *((_DWORD *)&thisType + 1) = v17;
    }
  }
  if ( (v4 & 4) != 0 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
    {
      BasedType = UnDecorator::getBasedType(&v42);
      v19 = operator+(&v43, 32, BasedType);
      v20 = DName::operator+(v19, &v41, &fitType);
      v21 = v20->node;
      v22 = *((_DWORD *)v20 + 1);
      fitType.node = v21;
      *((_DWORD *)&fitType + 1) = v22;
    }
    else
    {
      v24 = UnDecorator::getBasedType(&v41);
      DName::operator|=(&fitType, v24);
    }
  }
  if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
  {
    CallingConvention = UnDecorator::getCallingConvention(&v42);
    v26 = DName::operator+(CallingConvention, &v41, &fitType);
    v27 = v26->node;
    v28 = *((_DWORD *)v26 + 1);
    fitType.node = v27;
    *((_DWORD *)&fitType + 1) = v28;
  }
  else
  {
    v29 = UnDecorator::getCallingConvention(&v41);
    DName::operator|=(&fitType, v29);
  }
  if ( superType->node )
  {
    v30 = operator+(&v42, 40, &fitType);
    v31 = DName::operator+(v30, &v41, 41);
    v32 = v31->node;
    v33 = *((_DWORD *)v31 + 1);
    fitType.node = v32;
    *((_DWORD *)&fitType + 1) = v33;
  }
  Memory = HeapManager::getMemory(&heap, 8u, 0);
  if ( Memory )
  {
    Memory[4] = 0;
    *((_DWORD *)Memory + 1) &= 0xFFFF00FF;
    *(_DWORD *)Memory = 0;
    v35 = (DName *)Memory;
  }
  else
  {
    v35 = 0;
  }
  UnDecorator::getReturnType(&returnType, v35);
  ArgumentTypes = UnDecorator::getArgumentTypes(&v42);
  v37 = operator+(&v43, 40, ArgumentTypes);
  v38 = DName::operator+(v37, &v41, 41);
  DName::operator+=(&fitType, v38);
  if ( (UnDecorator::disableFlags & 0x60) != 0x60 && (v4 & 2) != 0 )
    DName::operator+=(&fitType, &thisType);
  if ( (UnDecorator::disableFlags & 0x100) != 0 )
  {
    ThrowTypes = UnDecorator::getThrowTypes(&v41);
    DName::operator|=(&fitType, ThrowTypes);
  }
  else
  {
    v39 = UnDecorator::getThrowTypes(&v41);
    DName::operator+=(&fitType, v39);
  }
  if ( v35 )
  {
    *v35 = fitType;
    v3 = result;
    *result = returnType;
    return v3;
  }
  DName::DName(result, DN_error);
  return result;
}
