<div class="container mainContainer">

    <div class="row">
        <div class="col-7">

            <h2>Posts For You</h2>

            <?php displayPosts('isFollowing'); ?>

        </div>
        <div class="col-5">

            <?php displaySearch(); ?>
            <hr>
            <?php displayPostBox(); ?>

        </div>
    </div>
    
</div>