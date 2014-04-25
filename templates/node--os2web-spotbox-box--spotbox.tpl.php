<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="caption">
    <?php if(!empty($spotbox_url)) : ?>
      <a href="<?php print $spotbox_url ?>">
    <?php endif; ?>

    <?php if(!empty($content['field_os2web_spotbox_text'])) : ?>
      <h3><?php print render($content['field_os2web_spotbox_text']); ?></h3>
    <?php endif; ?>

    <?php if(!empty($content['field_os2web_spotbox_big_image'])) : ?>
      <?php print render($content['field_os2web_spotbox_big_image']); ?>
    <?php endif; ?>
    <?php $image_render_array = media_youtube_file_formatter_image_view($file, $display, LANGUAGE_NONE); ?>
    <?php print render($content['field_os2web_spotbox_video']); ?>

    <?php if(!empty($spotbox_url)) : ?>
      </a>
    <?php endif; ?>
  </div>

</div> <!-- /.node -->
