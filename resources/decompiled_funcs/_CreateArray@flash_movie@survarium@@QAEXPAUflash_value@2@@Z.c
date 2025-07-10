void __usercall survarium::flash_movie::CreateArray(
        survarium::flash_movie *this@<ecx>,
        Scaleform::GFx::Value *value@<eax>)
{
  Scaleform::GFx::Movie::CreateArray(this->m_movie, value);
}
