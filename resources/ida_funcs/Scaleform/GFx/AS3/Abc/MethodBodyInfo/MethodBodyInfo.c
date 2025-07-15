void __thiscall Scaleform::GFx::AS3::Abc::MethodBodyInfo::MethodBodyInfo(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *this)
{
  this->obj_traits.Data.Data = 0;
  this->obj_traits.Data.Size = 0;
  this->obj_traits.Data.Policy.Capacity = 0;
  this->method_info_ind = -1;
  this->max_stack = -1;
  this->local_reg_count = -1;
  this->init_scope_depth = -1;
  this->max_scope_depth = -1;
  this->code.__vftable = (Scaleform::GFx::AS3::Abc::Code_vtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable';
  this->code.code.Data = &Scaleform::GFx::AS3::Abc::StringView::Empty;
  this->exception.info.Data.Data = 0;
  this->exception.info.Data.Size = 0;
  this->exception.info.Data.Policy.Capacity = 0;
}
