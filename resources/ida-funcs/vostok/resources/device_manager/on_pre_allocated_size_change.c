void __usercall vostok::resources::device_manager::on_pre_allocated_size_change(
        vostok::resources::device_manager *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 8) += this;
}
