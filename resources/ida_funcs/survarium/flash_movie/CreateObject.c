void __usercall survarium::flash_movie::CreateObject(
        survarium::flash_movie *this@<ecx>,
        Scaleform::GFx::Value *value@<eax>)
{
  Scaleform::GFx::Movie::CreateObject(this->m_movie, value, 0, 0, 0);
}
