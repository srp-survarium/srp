void __usercall vostok::render::speedtree_tree_base::speedtree_tree_base(
        vostok::render::speedtree_tree_base *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &stru_962594.m_buffers;
  *(_QWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_QWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 284) = 0;
}
