DName *__cdecl UnDecorator::getArrayType(DName *result, DName *superType)
{
  DName *p_arrayType; // eax
  DName *v3; // ecx
  int v4; // eax
  const DName *Dimension; // eax
  DName *v6; // eax
  const DName *v7; // eax
  DName *v8; // ecx
  DName *v9; // eax
  DName *v10; // eax
  int v11; // ecx
  DName *v12; // eax
  DName *v13; // eax
  DName *v14; // eax
  const DName *v15; // eax
  DName *v16; // [esp-10h] [ebp-44h]
  DName *p_newType; // [esp-8h] [ebp-3Ch]
  DName v18; // [esp+4h] [ebp-30h] BYREF
  DName v19; // [esp+Ch] [ebp-28h] BYREF
  DName v20; // [esp+14h] [ebp-20h] BYREF
  DName newType; // [esp+1Ch] [ebp-18h] BYREF
  DName arrayType; // [esp+24h] [ebp-10h] BYREF
  char v23; // [esp+2Ch] [ebp-8h] BYREF
  int noDimensions; // [esp+30h] [ebp-4h]

  if ( !*UnDecorator::gName )
  {
    if ( superType->node )
    {
      p_newType = &v18;
      v16 = &v19;
      v12 = operator+(&newType, 40, superType);
      v13 = DName::operator+(v12, &v20, ")[");
LABEL_22:
      v14 = DName::operator+(v13, v16, DN_truncated);
      v15 = DName::operator+(v14, p_newType, 93);
      UnDecorator::getBasicDataType(result, v15);
      return result;
    }
    p_newType = &v18;
    p_arrayType = &v19;
    v3 = &v20;
LABEL_21:
    v16 = p_arrayType;
    v13 = DName::operator=(v3, 91);
    goto LABEL_22;
  }
  noDimensions = UnDecorator::getNumberOfDimensions();
  if ( noDimensions < 0 )
    noDimensions = 0;
  if ( !noDimensions )
  {
    p_newType = &newType;
    p_arrayType = &arrayType;
    v3 = (DName *)&v23;
    goto LABEL_21;
  }
  *((_DWORD *)&arrayType + 1) &= 0xFFFF0000;
  arrayType.node = 0;
  if ( (*((_DWORD *)superType + 1) & 0x800) != 0 )
    DName::operator+=(&arrayType, "[]");
  while ( *((char *)&arrayType + 4) <= 1 )
  {
    v4 = noDimensions--;
    if ( !v4 || !*UnDecorator::gName )
      break;
    Dimension = UnDecorator::getDimension(&v19, 0);
    v6 = operator+(&v18, 91, Dimension);
    v7 = DName::operator+(v6, &v20, 93);
    DName::operator+=(&arrayType, v7);
  }
  if ( superType->node )
  {
    if ( (*((_DWORD *)superType + 1) & 0x800) != 0 )
    {
      v8 = superType;
    }
    else
    {
      v9 = operator+(&v20, 40, superType);
      v8 = DName::operator+(v9, &v19, 41);
    }
    arrayType = *DName::operator+(v8, &v18, &arrayType);
  }
  UnDecorator::getPrimaryDataType(&newType, &arrayType);
  v10 = result;
  v11 = *((_DWORD *)&newType + 1) | 0x800;
  result->node = newType.node;
  *((_DWORD *)result + 1) = v11;
  return v10;
}
