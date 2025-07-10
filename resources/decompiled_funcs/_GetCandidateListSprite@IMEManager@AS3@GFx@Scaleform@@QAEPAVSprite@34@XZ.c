Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::AS3::IMEManager::GetCandidateListSprite(
        Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ecx
  int v3; // esi
  int v5; // edi
  Scaleform::GFx::AS3::Value pdestVal; // [esp+0h] [ebp-10h] BYREF

  if ( (this->CandListVal.Type & 0x8F) == 1 )
    return 0;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovie->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(
    pObject,
    (Scaleform::GFx::ASStringNode *)&this->CandListVal,
    &pdestVal);
  if ( (pdestVal.Flags & 0x1F) - 12 > 3 )
  {
    if ( (pdestVal.Flags & 0x1F) > 9 )
    {
      if ( (pdestVal.Flags & 0x200) != 0 )
        goto LABEL_7;
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
    return 0;
  }
  v3 = *(_DWORD *)(pdestVal.value.VS._1.VInt + 20);
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
  {
    if ( (pdestVal.Flags & 0x1F) > 9 )
    {
      if ( (pdestVal.Flags & 0x200) != 0 )
      {
LABEL_7:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&pdestVal);
        return 0;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
    return 0;
  }
  else
  {
    v5 = *(_DWORD *)(pdestVal.value.VS._1.VInt + 48);
    if ( (pdestVal.Flags & 0x1F) > 9 )
    {
      if ( (pdestVal.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&pdestVal);
        return (Scaleform::GFx::Sprite *)v5;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
    return (Scaleform::GFx::Sprite *)v5;
  }
}
