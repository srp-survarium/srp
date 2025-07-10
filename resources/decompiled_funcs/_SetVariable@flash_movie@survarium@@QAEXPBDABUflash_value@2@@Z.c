void __userpurge survarium::flash_movie::SetVariable(
        const char *name@<ecx>,
        const Scaleform::GFx::Value *value@<eax>,
        survarium::flash_movie *this)
{
  Scaleform::GFx::Movie::SetVariable(this->m_movie, name, value, SV_Sticky);
}
