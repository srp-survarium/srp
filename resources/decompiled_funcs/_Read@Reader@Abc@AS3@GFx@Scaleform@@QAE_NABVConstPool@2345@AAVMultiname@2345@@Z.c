bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        int obj)
{
  const unsigned __int8 *v4; // eax
  const unsigned __int8 **p_CP; // ecx
  int v6; // edx
  bool result; // al
  Scaleform::GFx::AS3::Abc::MultinameKind v8; // edx
  int *v9; // esi
  char v10; // al
  Scaleform::GFx::AS3::Abc::Multiname *v11; // eax

  v4 = this->CP;
  p_CP = &this->CP;
  v6 = *v4;
  *p_CP = v4 + 1;
  result = 1;
  switch ( v6 )
  {
    case 7:
      v8 = MN_QName;
      break;
    case 9:
      v8 = MN_Multiname;
      break;
    case 13:
      v8 = MN_QNameA;
      break;
    case 14:
      v8 = MN_MultinameA;
      break;
    case 15:
      v8 = MN_RTQName;
      break;
    case 16:
      v8 = MN_RTQNameA;
      break;
    case 17:
      v8 = MN_RTQNameL;
      break;
    case 18:
      v8 = MN_RTQNameLA;
      break;
    case 27:
      v8 = MN_MultinameL;
      break;
    case 28:
      v8 = MN_MultinameLA;
      break;
    case 29:
      v8 = MN_Typename;
      break;
    default:
      v8 = MN_Invalid;
      result = 0;
      break;
  }
  v9 = (int *)obj;
  *(_DWORD *)(obj + 12) = v8;
  switch ( v8 )
  {
    case MN_QName:
    case MN_QNameA:
      if ( result )
      {
        *v9 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
        if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, v9 + 2) )
          return 1;
      }
      goto LABEL_17;
    case MN_RTQName:
    case MN_RTQNameA:
      if ( !result )
        goto LABEL_17;
      v9[2] = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      return 1;
    case MN_Multiname:
    case MN_MultinameA:
      if ( !result )
        goto LABEL_17;
      v9[2] = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v10 = Scaleform::GFx::AS3::Abc::Reader::Read(this, v9);
      goto LABEL_23;
    case MN_MultinameL:
    case MN_MultinameLA:
      if ( !result )
        goto LABEL_17;
      *v9 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      return 1;
    case MN_Typename:
      obj = 0;
      if ( !result )
        goto LABEL_17;
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj) )
        goto LABEL_17;
      v11 = &cp->const_multiname.Data.Data[obj];
      *v9 = v11->Ind;
      v9[1] = v11->NextIndex;
      v9[2] = v11->NameIndex;
      v9[3] = v11->Kind;
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj) || obj != 1 )
        goto LABEL_17;
      v10 = Scaleform::GFx::AS3::Abc::Reader::Read(this, v9 + 1);
LABEL_23:
      if ( v10 )
        return 1;
LABEL_17:
      v9[3] = 32;
      return 0;
    default:
      if ( !result )
        v9[3] = 32;
      return result;
  }
}
