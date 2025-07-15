Scaleform::Render::Font *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFontData(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceId rid)
{
  Scaleform::GFx::FontDataUseNode *volatile Value; // eax

  Value = this->BindData.pFonts.Value;
  if ( !Value )
    return 0;
  while ( Value->Id.Id != rid.Id )
  {
    Value = Value->pNext.Value;
    if ( !Value )
      return 0;
  }
  return Value->pFontData.pObject;
}
