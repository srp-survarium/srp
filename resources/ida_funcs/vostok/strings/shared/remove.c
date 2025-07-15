void __usercall vostok::strings::shared::remove(vostok::strings::shared::profile *profile@<eax>)
{
  vostok::strings::shared::manager::remove(s_manager.m_variable, s_manager.m_variable, profile);
}
