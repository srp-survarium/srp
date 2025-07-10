bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitInfo *obj)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *v2; // esi
  const unsigned __int8 **p_CP; // edi
  unsigned __int8 v5; // cl
  bool v6; // sf
  bool result; // al
  bool IsValidValueKind; // bl
  unsigned __int8 kind; // [esp+Ch] [ebp-4h]

  v2 = obj;
  p_CP = &this->CP;
  v2->name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = *(*p_CP)++;
  v6 = v2->name_ind < 0;
  v2->kind = v5;
  if ( v6 )
    return 0;
  switch ( v5 & 0xF )
  {
    case 0:
    case 6:
      obj = 0;
      if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->SlotId) )
      {
        if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->Ind) )
        {
          if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, (int *)&obj) )
          {
            IsValidValueKind = 1;
            if ( !obj )
              goto LABEL_15;
            kind = *(*p_CP)++;
            IsValidValueKind = Scaleform::GFx::AS3::Abc::IsValidValueKind(kind);
            v2->default_value.ValueIndex = (int)obj;
            v2->default_value.Kind = kind;
            if ( IsValidValueKind )
              goto LABEL_15;
          }
        }
      }
      goto LABEL_9;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->SlotId)
        || !Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->Ind)
        || v2->SlotId < 0
        || v2->Ind < 0 )
      {
        goto LABEL_9;
      }
      IsValidValueKind = 1;
LABEL_15:
      if ( (v2->kind & 0x40) != 0 )
        IsValidValueKind = Scaleform::GFx::AS3::Abc::Reader::Read(
                             this,
                             (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)&v2->meta_info) != 0;
      result = IsValidValueKind;
      break;
    default:
LABEL_9:
      result = 0;
      break;
  }
  return result;
}
