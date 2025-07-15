DName *__cdecl UnDecorator::getArrayType(DName *result, DName *superType)
{
  DName *p_superTypea; // eax
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
  DName *p_resulta; // [esp-10h] [ebp-44h]
  DName *v17; // [esp-8h] [ebp-3Ch]
  DName v18; // [esp+4h] [ebp-30h] BYREF
  DName resulta; // [esp+Ch] [ebp-28h] BYREF
  DName v20; // [esp+14h] [ebp-20h] BYREF
  DName v21; // [esp+1Ch] [ebp-18h] BYREF
  DName superTypea; // [esp+24h] [ebp-10h] BYREF
  char v23; // [esp+2Ch] [ebp-8h] BYREF
  int NumberOfDimensions; // [esp+30h] [ebp-4h]

  if ( !*UnDecorator::gName )
  {
    if ( superType->node )
    {
      v17 = &v18;
      p_resulta = &resulta;
      v12 = operator+(&v21, 40, superType);
      v13 = DName::operator+(v12, &v20, ")[");
LABEL_22:
      v14 = DName::operator+(v13, p_resulta, DN_truncated);
      v15 = DName::operator+(v14, v17, 93);
      UnDecorator::getBasicDataType(result, v15);
      return result;
    }
    v17 = &v18;
    p_superTypea = &resulta;
    v3 = &v20;
LABEL_21:
    p_resulta = p_superTypea;
    v13 = DName::operator=(v3, 91);
    goto LABEL_22;
  }
  NumberOfDimensions = UnDecorator::getNumberOfDimensions();
  if ( NumberOfDimensions < 0 )
    NumberOfDimensions = 0;
  if ( !NumberOfDimensions )
  {
    v17 = &v21;
    p_superTypea = &superTypea;
    v3 = (DName *)&v23;
    goto LABEL_21;
  }
  *((_DWORD *)&superTypea + 1) &= 0xFFFF0000;
  superTypea.node = 0;
  if ( (*((_DWORD *)superType + 1) & 0x800) != 0 )
    DName::operator+=(&superTypea, "[]");
  while ( *((char *)&superTypea + 4) <= 1 )
  {
    v4 = NumberOfDimensions--;
    if ( !v4 || !*UnDecorator::gName )
      break;
    Dimension = UnDecorator::getDimension(&resulta, 0);
    v6 = operator+(&v18, 91, Dimension);
    v7 = DName::operator+(v6, &v20, 93);
    DName::operator+=(&superTypea, v7);
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
      v8 = DName::operator+(v9, &resulta, 41);
    }
    superTypea = *DName::operator+(v8, &v18, &superTypea);
  }
  UnDecorator::getPrimaryDataType(&v21, &superTypea);
  v10 = result;
  v11 = *((_DWORD *)&v21 + 1) | 0x800;
  result->node = v21.node;
  *((_DWORD *)result + 1) = v11;
  return v10;
}
