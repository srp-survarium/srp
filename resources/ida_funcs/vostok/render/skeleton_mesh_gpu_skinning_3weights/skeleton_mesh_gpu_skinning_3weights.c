void __usercall vostok::render::skeleton_mesh_gpu_skinning_3weights::skeleton_mesh_gpu_skinning_3weights(
        vostok::render::skeleton_mesh_gpu_skinning_3weights *this@<ecx>,
        DXGI_FORMAT **a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  a2[1] = (DXGI_FORMAT *)3;
  *a2 = &stru_966A14.m_desc.Format;
  a2[39] = 0;
}
