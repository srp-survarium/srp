void __userpurge vostok::render::scene::remove_streamable_texture_instance(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        vostok::render::decal_instance *decal)
{
  vostok::buffer_vector<void const *> *v4; // ecx
  vostok::render::scene *v5; // ecx

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_texture_streaming )
  {
    vostok::render::texture_streaming_async_worker::ensure_completion(
      (vostok::render::texture_streaming_async_worker *)this,
      (int)&unk_8B9588 + a2);
    vostok::buffer_vector<void const *>::push_back(v4, (int)&loc_1C6188 + a2, (const void **)&decal);
    vostok::render::scene::process_pending_remove_texture_instances(v5, a2);
  }
}
