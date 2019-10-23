<?php

session_start();

$link = mysqli_connect('localhost:3306', 'user', 'password', 'camagru');

    if (mysqli_connect_errno()) {
        print_r(mysqli_connect_error());
        exit();
    }

    if ($_GET['function'] == "logout") {

        session_unset();

    }

        function time_since($since) {
        $chunks = array(
            array(60 * 60 * 24 * 365 , 'year'),
            array(60 * 60 * 24 * 30 , 'month'),
            array(60 * 60 * 24 * 7, 'week'),
            array(60 * 60 * 24 , 'day'),
            array(60 * 60 , 'hour'),
            array(60 , 'min'),
            array(1 , 's')
        );

        for ($i = 0, $j = count($chunks); $i < $j; $i++) {
            $seconds = $chunks[$i][0];
            $name = $chunks[$i][1];
            if (($count = floor($since / $seconds)) != 0) {
                break;
            }
        }

        $print = ($count == 1) ? '1 '.$name : "$count {$name}s";
        return $print;
        }


    function displayPosts($type) {
        
        global $link;
        
        if ($type == 'public') {
            
            $whereClause = "";
            
        } else if ($type == 'isFollowing') {
            
            $query = "SELECT * FROM isFollowing WHERE follower = ". mysqli_real_escape_string($link, $_SESSION['id']);
            
            $result = mysqli_query($link, $query);
            
            $whereClause = "";
            
            while ($row = mysqli_fetch_assoc($result)) {
                
                if ($whereClause == "") $whereClause = "WHERE";
                else $whereClause.= " OR";
                $whereClause.= " userid = ".$row['isFollowing'];
                
            }
        }
        
        $query = "SELECT * FROM posts ".$whereClause." ORDER BY `datetime` DESC LIMIT 10";
        
        $result = mysqli_query($link, $query);
        
        if (mysqli_num_rows($result) == 0) {
            
            echo "There are no posts to display";
            
        } else {
            
            while ($row = mysqli_fetch_assoc($result)) {
                
                $userQuery = "SELECT * FROM users WHERE id = ".mysqli_real_escape_string($link, $row['userid'])." LIMIT 1";
                $userQueryResult = mysqli_query($link, $userQuery);
                $user = mysqli_fetch_assoc($userQueryResult);
                
                echo "<div class='post'><p>".$user['email']." <span class='time'>".time_since(time() - strtotime($row['datetime']))." ago</span>: </p>";
                
                echo "<p>".$row['post_text']."</p>";
                
                echo "<p><a class='toggleFollow' data-userId='".$row['userid']."'>";
                
                $isFollowingQuery = "SELECT * FROM isFollowing WHERE follower = ". mysqli_real_escape_string($link, $_SESSION['id'])." AND isFollowing = ". mysqli_real_escape_string($link, $row['userid'])." LIMIT 1";
                $isFollowingQueryresult = mysqli_query($link, $isFollowingQuery);
                if (mysqli_num_rows($isFollowingQueryresult) > 0) {
            
                    echo "Unfollow";
                    
                } else {
                    
                    echo "Follow";
                    
                }
                
                echo "</a></p></div>";
                
            }
            
        }
        
    }

    function displaySearch() {
        
        echo '<form class="form-inline">
            <div class="form-group"> 
              <input type="text" class="form-control mb-2 mr-sm-2" id="search" placeholder="Search">
            </div>
              <button class="btn btn-primary mb-2">Search Posts</button>
            </form>';
        
    }

    function displayPostBox() {
        
        if ($_SESSION['id'] > 0) {
            
            echo '<form class="form">
            <div class="form-group"> 
              <textarea type="text" class="form-control mb-2 mr-sm-2" id="postContent"></textarea>
            </div>
              <button class="btn btn-primary mb-2">Post</button>
            </form>';
            
        }
        
    }
?>