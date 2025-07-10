void __thiscall survarium::stats_stream::~stats_stream(survarium::stats_stream *this, survarium::stats_stream *thisa)
{
  int f; // esi
  char *bytes_per_second_graph; // edi
  char *graph; // edi
  int v5; // esi
  survarium::flash_text_manager *text_manager; // esi
  survarium::flash_text_manager *v7; // esi
  survarium::flash_text_manager *v8; // esi
  survarium::flash_text_manager *v9; // esi

  if ( thisa->text_manager )
  {
    f = (int)survarium::g_allocator.f_.f_;
    bytes_per_second_graph = (char *)thisa->bytes_per_second_graph;
    if ( bytes_per_second_graph )
    {
      survarium::stats_graph::~stats_graph((survarium::stats_graph *)this, (int)bytes_per_second_graph);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(*(malloc_state **)(f + 20), bytes_per_second_graph);
      thisa->bytes_per_second_graph = 0;
    }
    graph = (char *)thisa->graph;
    v5 = (int)survarium::g_allocator.f_.f_;
    if ( graph )
    {
      survarium::stats_graph::~stats_graph((survarium::stats_graph *)this, (int)graph);
      *(_BYTE *)(v5 + 42) = 0;
      vostok_mspace_free(*(malloc_state **)(v5 + 20), graph);
      thisa->graph = 0;
    }
    text_manager = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->count_per_second.text_impl);
    thisa->count_per_second.text_impl = 0;
    thisa->count_per_second.owner = 0;
    thisa->count_per_second.visible = 0;
    text_manager->need_capture = 1;
    v7 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->bits_per_second.text_impl);
    thisa->bits_per_second.text_impl = 0;
    thisa->bits_per_second.owner = 0;
    thisa->bits_per_second.visible = 0;
    v7->need_capture = 1;
    v8 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->bytes.text_impl);
    thisa->bytes.text_impl = 0;
    thisa->bytes.owner = 0;
    thisa->bytes.visible = 0;
    v8->need_capture = 1;
    v9 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->count.text_impl);
    thisa->count.text_impl = 0;
    thisa->count.owner = 0;
    thisa->count.visible = 0;
    v9->need_capture = 1;
  }
}
