void __userpurge survarium::flash_movie::CreateFunction(
        Scaleform::GFx::Value *value@<edx>,
        survarium::flash_function_handler *func@<eax>,
        survarium::flash_movie *this)
{
  Scaleform::GFx::Movie::CreateFunction(this->m_movie, value, func->impl, 0);
}
