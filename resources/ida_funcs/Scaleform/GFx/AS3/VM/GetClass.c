Scaleform::GFx::AS3::Class *__thiscall Scaleform::GFx::AS3::VM::GetClass(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *gname,
        Scaleform::GFx::ASStringNode *appDomain)
{
  unsigned int v3; // ebx
  unsigned int Size; // edi
  unsigned int pManager; // edx
  unsigned int v7; // eax
  signed int LastChar; // eax
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  const char *v13; // edi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *ClassVector; // eax
  int v16; // esi
  Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASString *v19; // esi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::StringDataPtr subtype_name; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+18h] [ebp-18h] BYREF

  v3 = 0;
  if ( !gname->pManager )
    return 0;
  if ( (_S15 & 1) != 0 )
  {
    Size = vecPref.Size;
  }
  else
  {
    _S15 |= 1u;
    Size = 8;
    vecPref.pStr = "Vector.<";
    vecPref.Size = 8;
  }
  pManager = (unsigned int)gname->pManager;
  if ( pManager <= Size )
    goto LABEL_16;
  v7 = pManager - Size;
  if ( pManager < Size )
    v7 = (unsigned int)gname->pManager;
  subtype_name.pStr = gname->pData;
  subtype_name.Size = pManager - v7;
  if ( !Scaleform::StringDataPtr::operator==(&subtype_name, &vecPref) )
  {
LABEL_16:
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, this, gname);
    v18 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, &mn, appDomain);
    v19 = v18;
    if ( v18 )
    {
      ((void (__thiscall *)(Scaleform::GFx::ASString *))v18->pNode[1].Size)(v18);
      if ( !this->HandleException )
      {
        pNode = v19[25].pNode;
        if ( !pNode[2].Size )
          (*((void (__thiscall **)(Scaleform::GFx::ASStringNode *))pNode->pData + 11))(pNode);
        v3 = pNode[2].Size;
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return (Scaleform::GFx::AS3::Class *)v3;
  }
  LastChar = Scaleform::StringDataPtr::FindLastChar((Scaleform::StringDataPtr *)gname, 62, 0xFFFFFFFF);
  if ( LastChar <= 0 )
    return (Scaleform::GFx::AS3::Class *)v3;
  v9 = (unsigned int)gname->pManager;
  v10 = vecPref.Size;
  if ( v9 < vecPref.Size )
    v10 = (unsigned int)gname->pManager;
  v11 = v9 - v10;
  v12 = v9 - LastChar;
  v13 = &gname->pData[v10];
  if ( v11 < v12 )
    v12 = v11;
  subtype_name.Size = v11 - v12;
  subtype_name.pStr = v13;
  Class = Scaleform::GFx::AS3::VM::GetClass(this, &subtype_name, (Scaleform::GFx::AS3::VMAppDomain *)appDomain);
  if ( !Class )
    return 0;
  Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&mn, Class);
  ClassVector = Scaleform::GFx::AS3::VM::GetClassVector(this);
  v16 = (int)ClassVector->ApplyTypeArgs(ClassVector, 1u, (const Scaleform::GFx::AS3::Value *)&mn);
  Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&mn);
  return (Scaleform::GFx::AS3::Class *)v16;
}
