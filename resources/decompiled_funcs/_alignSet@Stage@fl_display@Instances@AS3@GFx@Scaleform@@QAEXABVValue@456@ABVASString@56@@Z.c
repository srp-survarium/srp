void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::alignSet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *value)
{
  unsigned int v4; // edi
  int Length; // esi
  unsigned int CharAt; // ebx
  int v7; // eax
  void (__thiscall *v8)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::GFx::ASStringNode *v9; // eax

  value = Scaleform::GFx::ASConstString::ToUpperNode((Scaleform::GFx::ASConstString *)value);
  ++value->RefCount;
  v4 = 0;
  Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&value);
  if ( Length < 1 )
    goto LABEL_24;
  CharAt = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&value, 0);
  if ( Length >= 2 )
    v4 = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&value, (const char *)1);
  if ( CharAt == 84 )
  {
    if ( v4 != 76 )
    {
      if ( v4 != 82 )
      {
        v7 = 1;
        goto LABEL_25;
      }
      goto LABEL_13;
    }
LABEL_10:
    v7 = 5;
    goto LABEL_25;
  }
  if ( CharAt != 76 )
  {
    if ( CharAt == 82 )
    {
      if ( v4 == 84 )
      {
LABEL_13:
        v7 = 6;
        goto LABEL_25;
      }
      if ( v4 != 66 )
      {
        v7 = 4;
        goto LABEL_25;
      }
LABEL_21:
      v7 = 8;
      goto LABEL_25;
    }
    if ( CharAt == 66 )
    {
      if ( v4 == 76 )
      {
LABEL_19:
        v7 = 7;
        goto LABEL_25;
      }
      if ( v4 != 82 )
      {
        v7 = 2;
        goto LABEL_25;
      }
      goto LABEL_21;
    }
LABEL_24:
    v7 = 0;
    goto LABEL_25;
  }
  if ( v4 == 84 )
    goto LABEL_10;
  if ( v4 == 66 )
    goto LABEL_19;
  v7 = 3;
LABEL_25:
  v8 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), int))(*(_DWORD *)v8 + 60))(v8, v7);
  v9 = value;
  --value->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
