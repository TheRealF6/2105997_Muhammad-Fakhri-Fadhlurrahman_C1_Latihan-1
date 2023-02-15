<?php

class Main
{
    function __construct(){
    }

    public static function Utama()
    {
        $local_this = new Utama();
        return $local_this;
    }

    public static function main(&$args)
    {
        try
        {
            $writer = array();
            $writer.write("Ardi 2101210 Ilkom FPMIPA");
            $writer.write("Andi 2101410 Pilkom FPMIPA");
            $writer.write("Aldo 2101310 Ilkom FPMIPA");
            $writer.close();
        } catch ( Exception $e) {
            $e.printStackTrace();
        }
        try
        {
            $reader = array();
            $character;
            while (($character = $reader.read()) != -1)
            {
                
                echo chr($character);
            }

            $reader.close();
        } catch ( Exception $e) {
            $e.printStackTrace();
        }
    }
}

Utama::main($argv);

?>