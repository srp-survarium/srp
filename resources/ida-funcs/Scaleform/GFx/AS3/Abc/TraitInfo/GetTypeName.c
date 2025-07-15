const Scaleform::GFx::AS3::Abc::Multiname *__thiscall Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(
        Scaleform::GFx::AS3::Abc::TraitInfo *this,
        const Scaleform::GFx::AS3::Abc::File *f)
{
  if ( (this->kind & 0xF) != 0 && (this->kind & 0xF) != 6 )
    return &f->Const_Pool.const_multiname.Data.Data[f->AS3_Classes.Info.Data.Data[this->Ind]->inst_info.name_ind];
  else
    return &f->Const_Pool.const_multiname.Data.Data[this->Ind];
}
