void __thiscall vostok::vfs::query_mount_arguments::~query_mount_arguments(vostok::vfs::query_mount_arguments *this)
{
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->callback);
}
