void __thiscall survarium::stats_row::~stats_row(survarium::stats_row *this, survarium::stats_row *thisa)
{
  int f; // esi
  char *data_bytes_per_second_graph; // edi
  survarium::flash_text_manager *text_manager; // esi
  survarium::flash_text_manager *v5; // esi
  survarium::flash_text_manager *v6; // esi
  survarium::flash_text_manager *v7; // esi
  survarium::flash_text_manager *v8; // esi
  survarium::stats_stream *v9; // ecx

  if ( thisa->text_manager )
  {
    f = (int)survarium::g_allocator.f_.f_;
    data_bytes_per_second_graph = (char *)thisa->data_bytes_per_second_graph;
    if ( data_bytes_per_second_graph )
    {
      survarium::stats_graph::~stats_graph((survarium::stats_graph *)this, (int)data_bytes_per_second_graph);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(*(malloc_state **)(f + 20), data_bytes_per_second_graph);
      thisa->data_bytes_per_second_graph = 0;
    }
    text_manager = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->messages_per_second.text_impl);
    thisa->messages_per_second.text_impl = 0;
    thisa->messages_per_second.owner = 0;
    thisa->messages_per_second.visible = 0;
    text_manager->need_capture = 1;
    v5 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->data_bits_per_message.text_impl);
    thisa->data_bits_per_message.text_impl = 0;
    thisa->data_bits_per_message.owner = 0;
    thisa->data_bits_per_message.visible = 0;
    v5->need_capture = 1;
    v6 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->data_bits_per_second.text_impl);
    thisa->data_bits_per_second.text_impl = 0;
    thisa->data_bits_per_second.owner = 0;
    thisa->data_bits_per_second.visible = 0;
    v6->need_capture = 1;
    v7 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->data_bytes.text_impl);
    thisa->data_bytes.text_impl = 0;
    thisa->data_bytes.owner = 0;
    thisa->data_bytes.visible = 0;
    v7->need_capture = 1;
    v8 = thisa->text_manager;
    Scaleform::RefCountNTSImpl::Release(thisa->caption.text_impl);
    thisa->caption.text_impl = 0;
    thisa->caption.owner = 0;
    thisa->caption.visible = 0;
    v8->need_capture = 1;
  }
  survarium::stats_stream::~stats_stream((survarium::stats_stream *)this, &thisa->messages);
  survarium::stats_stream::~stats_stream(v9, &thisa->packets);
}
